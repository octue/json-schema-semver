import wrapper from './dist/wrapper.js';

export async function version(from, to) {
  // We need to pass strings to WebAssembly
  const effective_from = typeof from === 'string' ? from : JSON.stringify(from);
  const effective_to = typeof to === 'string' ? to : JSON.stringify(to);
  return (await wrapper()).version(effective_from, effective_to);
}

export async function suggest(base, proposed, options = {}) {
  // We need to pass strings to WebAssembly, and an empty string means none
  const effective_base = base === null || base === undefined
    ? '' : (typeof base === 'string' ? base : JSON.stringify(base));
  const effective_proposed = typeof proposed === 'string'
    ? proposed : JSON.stringify(proposed);
  const result = (await wrapper()).suggest(
    effective_base,
    effective_proposed,
    options.baseVersion ?? '',
    options.stage ?? 'stable',
    options.initialVersion ?? '0.0.1');
  if (typeof result.error === 'string') {
    throw new Error(result.error);
  }

  return result;
}

export async function getBaseDialect(schema) {
  // We need to pass strings to WebAssembly
  const effective_schema = typeof schema === 'string' ? schema : JSON.stringify(schema);
  return (await wrapper()).getBaseDialect(effective_schema);
}
