declare module "@octue/json-schema-semver" {
  export type VersionChangeType = "major" | "minor" | "patch" | "equal" | null;

  export type CompatibilityType =
    | "compatible"
    | "incompatible"
    | "skip"
    | "unknown";

  export interface Trace {
    compatibility: CompatibilityType;
    left: string | null;
    right: string | null;
  }

  export interface VersionResult {
    version: VersionChangeType;
    traces: Trace[];
  }

  /**
   * Compare two version structures and determine the type of version change.
   *
   * @param from - The original version object or JSON string.
   * @param to - The target version object or JSON string.
   * @returns A promise that resolves to the version comparison result.
   */
  export function version(
    from: string | object,
    to: string | object
  ): Promise<VersionResult>;

  export type ChangeType =
    | "equal"
    | "initial"
    | "patch"
    | "minor"
    | "major"
    | null;

  export type BreakingLevel = "major" | "minor" | "patch";

  export interface SuggestOptions {
    /** The semantic version of the base schema. */
    baseVersion?: string;
    /**
     * Which part of the version a breaking change bumps. `major` (the
     * default) is standard semantic versioning, `minor` is for versions
     * below 1.0.0 and `patch` is for versions below 0.1.0.
     */
    breaking?: BreakingLevel;
    /** The version to suggest if there is no base schema (`0.0.1`). */
    initialVersion?: string;
  }

  export interface Suggestion {
    /** Null if there is no base version or the schemas are not comparable. */
    version: string | null;
    /** Null if the schemas are not comparable. */
    change: ChangeType;
    traces: Trace[];
  }

  /**
   * Suggest the semantic version of a proposed schema.
   *
   * @param base - The schema to compare against, or null if there is none.
   * @param proposed - The proposed schema object or JSON string.
   * @param options - The base version and how to bump it.
   * @returns A promise that resolves to the suggestion. It rejects if a
   * version is invalid or too high for the breaking level.
   */
  export function suggest(
    base: string | object | null,
    proposed: string | object,
    options?: SuggestOptions
  ): Promise<Suggestion>;

  /**
   * Get the base dialect of a schema.
   *
   * @param schema - The schema object or JSON string.
   * @returns A promise that resolves to the base dialect URI, if any.
   */
  export function getBaseDialect(schema: string | object): string | null;
}
