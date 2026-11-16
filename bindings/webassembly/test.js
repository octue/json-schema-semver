import test from 'node:test';
import { strict as assert } from 'node:assert';
import { version, suggest, getBaseDialect } from './json-schema-semver.js';

test('const to enum', async (t) => {
  const from = {
    $schema: 'https://json-schema.org/draft/2020-12/schema',
    const: 'foo'
  };

  const to = {
    $schema: 'https://json-schema.org/draft/2020-12/schema',
    enum: [ 'foo', 'bar' ]
  };

  assert.deepStrictEqual(await version(from, to), {
    version: "minor",
    traces: [
      {
        compatibility: "incompatible",
        left: "/const",
        right: "/enum"
      }
    ]
  });
});

test('equal', async (t) => {
  const from = {
    $schema: 'https://json-schema.org/draft/2020-12/schema',
    const: 'foo'
  };

  const to = {
    $schema: 'https://json-schema.org/draft/2020-12/schema',
    const: 'foo'
  };

  assert.deepStrictEqual(await version(from, to), {
    version: "equal",
    traces: []
  });
});

test('base dialect: 2020-12', async (t) => {
  const schema = {
    $schema: 'https://json-schema.org/draft/2020-12/schema',
    const: 'foo'
  };

  assert.deepStrictEqual(await getBaseDialect(schema),
    'https://json-schema.org/draft/2020-12/schema');
});

test('base dialect: draft7', async (t) => {
  const schema = {
    $schema: 'http://json-schema.org/draft-07/schema#',
    const: 'foo'
  };

  assert.deepStrictEqual(await getBaseDialect(schema),
    'http://json-schema.org/draft-07/schema#');
});

test('base dialect: unknown', async (t) => {
  const schema = {
    const: 'foo'
  };

  assert.deepStrictEqual(await getBaseDialect(schema), null);
});

const SCHEMA_BASE = {
  $schema: 'https://json-schema.org/draft/2020-12/schema',
  const: 'foo'
};

const SCHEMA_MINOR = {
  $schema: 'https://json-schema.org/draft/2020-12/schema',
  enum: [ 'foo', 'bar' ]
};

const SCHEMA_MAJOR = {
  $schema: 'https://json-schema.org/draft/2020-12/schema',
  const: 'bar'
};

test('suggest: minor change with base version', async (t) => {
  assert.deepStrictEqual(
    await suggest(SCHEMA_BASE, SCHEMA_MINOR, { baseVersion: '2.3.1' }), {
      version: '2.4.0',
      change: 'minor',
      traces: [
        {
          compatibility: 'incompatible',
          left: '/const',
          right: '/enum'
        }
      ]
    });
});

test('suggest: strings', async (t) => {
  const result = await suggest(JSON.stringify(SCHEMA_BASE),
    JSON.stringify(SCHEMA_MINOR), { baseVersion: '2.3.1' });
  assert.equal(result.version, '2.4.0');
});

test('suggest: no base version', async (t) => {
  const result = await suggest(SCHEMA_BASE, SCHEMA_MINOR);
  assert.equal(result.version, null);
  assert.equal(result.change, 'minor');
});

test('suggest: initial', async (t) => {
  assert.deepStrictEqual(await suggest(null, SCHEMA_BASE), {
    version: '0.0.1',
    change: 'initial',
    traces: []
  });
});

test('suggest: custom initial version', async (t) => {
  const result = await suggest(null, SCHEMA_BASE, { initialVersion: '0.1.0' });
  assert.equal(result.version, '0.1.0');
  assert.equal(result.change, 'initial');
});

test('suggest: equal pre-release', async (t) => {
  const result = await suggest(SCHEMA_BASE, SCHEMA_BASE,
    { baseVersion: '2.3.1-rc0' });
  assert.equal(result.version, '2.3.1-rc1');
  assert.equal(result.change, 'equal');
});

test('suggest: breaking levels', async (t) => {
  assert.equal((await suggest(SCHEMA_BASE, SCHEMA_MAJOR,
    { baseVersion: '0.3.1' })).version, '1.0.0');
  assert.equal((await suggest(SCHEMA_BASE, SCHEMA_MAJOR,
    { baseVersion: '0.3.1', breaking: 'major' })).version, '1.0.0');
  assert.equal((await suggest(SCHEMA_BASE, SCHEMA_MAJOR,
    { baseVersion: '0.3.1', breaking: 'minor' })).version, '0.4.0');
  assert.equal((await suggest(SCHEMA_BASE, SCHEMA_MAJOR,
    { baseVersion: '0.0.3', breaking: 'patch' })).version, '0.0.4');
});

test('suggest: base version too high for the breaking level', async (t) => {
  await assert.rejects(
    suggest(SCHEMA_BASE, SCHEMA_MAJOR,
      { baseVersion: '0.3.1', breaking: 'patch' }),
    { message: 'A breaking change cannot bump the patch number of version ' +
        '0.3.1: the `breaking` level must be `minor` or `major`' });
});

test('suggest: invalid base version', async (t) => {
  await assert.rejects(
    suggest(SCHEMA_BASE, SCHEMA_MAJOR, { baseVersion: '1.2' }),
    { message: 'Not a valid semantic version: 1.2' });
});

test('suggest: invalid breaking level', async (t) => {
  await assert.rejects(
    suggest(SCHEMA_BASE, SCHEMA_MAJOR,
      { baseVersion: '1.2.3', breaking: 'huge' }),
    { message: "`breaking` must be one of 'major', 'minor' or 'patch'" });
});

test('suggest: unknown', async (t) => {
  const from = {
    $schema: 'https://json-schema.org/draft/2020-12/schema',
    type: 'string',
    minimum: 1
  };

  const result = await suggest(from, SCHEMA_BASE, { baseVersion: '1.0.0' });
  assert.equal(result.version, null);
  assert.equal(result.change, null);
  assert.equal(result.traces.length, 1);
});
