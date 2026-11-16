#include <gtest/gtest.h>
#include <octue/jss.h>
#include <octue/jss_suggest.h>

#include <optional>
#include <stdexcept>
#include <string>

using octue::jss::Breaking;
using octue::jss::bump;
using octue::jss::Change;
using octue::jss::SemVer;
using octue::jss::suggest;

static const auto SCHEMA_BASE{sourcemeta::core::parse_json(R"JSON({
  "$schema": "https://json-schema.org/draft/2020-12/schema",
  "const": "foo"
})JSON")};

// Only an annotation changes
static const auto SCHEMA_PATCH{sourcemeta::core::parse_json(R"JSON({
  "$schema": "https://json-schema.org/draft/2020-12/schema",
  "description": "A constant",
  "const": "foo"
})JSON")};

// Accepts everything the base does and more
static const auto SCHEMA_MINOR{sourcemeta::core::parse_json(R"JSON({
  "$schema": "https://json-schema.org/draft/2020-12/schema",
  "enum": [ "foo", "bar" ]
})JSON")};

// Does not accept what the base does
static const auto SCHEMA_MAJOR{sourcemeta::core::parse_json(R"JSON({
  "$schema": "https://json-schema.org/draft/2020-12/schema",
  "const": "bar"
})JSON")};

static const auto SCHEMA_UNKNOWN_FROM{sourcemeta::core::parse_json(R"JSON({
  "$schema": "https://json-schema.org/draft/2020-12/schema",
  "type": "string",
  "minimum": 1
})JSON")};

// Breaking level: major (standard semantic versioning)

TEST(JSS_bump, breaking_major_stable_major) {
  EXPECT_EQ(bump(SemVer::Major, "2.3.1"), "3.0.0");
}

TEST(JSS_bump, breaking_major_stable_minor) {
  EXPECT_EQ(bump(SemVer::Minor, "2.3.1"), "2.4.0");
}

TEST(JSS_bump, breaking_major_stable_patch) {
  EXPECT_EQ(bump(SemVer::Patch, "2.3.1"), "2.3.2");
}

TEST(JSS_bump, breaking_major_stable_equal) {
  EXPECT_EQ(bump(SemVer::Equal, "2.3.1"), "2.3.1");
}

TEST(JSS_bump, breaking_major_stable_major_other) {
  EXPECT_EQ(bump(SemVer::Major, "1.1.3", Breaking::Major), "2.0.0");
}

TEST(JSS_bump, breaking_major_zero_minor_major) {
  EXPECT_EQ(bump(SemVer::Major, "0.1.0", Breaking::Major), "1.0.0");
}

TEST(JSS_bump, breaking_major_zero_minor_minor) {
  EXPECT_EQ(bump(SemVer::Minor, "0.1.9", Breaking::Major), "0.2.0");
}

TEST(JSS_bump, breaking_major_zero_minor_patch) {
  EXPECT_EQ(bump(SemVer::Patch, "0.1.9", Breaking::Major), "0.1.10");
}

TEST(JSS_bump, breaking_major_zero_patch_major) {
  EXPECT_EQ(bump(SemVer::Major, "0.0.4", Breaking::Major), "1.0.0");
}

// Breaking level: minor (0.x development)

TEST(JSS_bump, breaking_minor_major) {
  EXPECT_EQ(bump(SemVer::Major, "0.1.9", Breaking::Minor), "0.2.0");
}

TEST(JSS_bump, breaking_minor_minor) {
  EXPECT_EQ(bump(SemVer::Minor, "0.1.9", Breaking::Minor), "0.2.0");
}

TEST(JSS_bump, breaking_minor_patch) {
  EXPECT_EQ(bump(SemVer::Patch, "0.1.9", Breaking::Minor), "0.1.10");
}

TEST(JSS_bump, breaking_minor_equal) {
  EXPECT_EQ(bump(SemVer::Equal, "0.1.9", Breaking::Minor), "0.1.9");
}

TEST(JSS_bump, breaking_minor_zero_patch_major) {
  EXPECT_EQ(bump(SemVer::Major, "0.0.4", Breaking::Minor), "0.1.0");
}

TEST(JSS_bump, breaking_minor_stable_error) {
  EXPECT_THROW(bump(SemVer::Major, "1.0.0", Breaking::Minor),
               octue::jss::BreakingLevelError);
  EXPECT_THROW(bump(SemVer::Equal, "1.2.0", Breaking::Minor),
               octue::jss::BreakingLevelError);
}

TEST(JSS_bump, breaking_minor_stable_pre_release_error) {
  EXPECT_THROW(bump(SemVer::Patch, "1.0.0-rc.1", Breaking::Minor),
               octue::jss::BreakingLevelError);
}

TEST(JSS_bump, breaking_minor_stable_error_message) {
  try {
    bump(SemVer::Major, "1.2.0", Breaking::Minor);
    FAIL();
  } catch (const octue::jss::BreakingLevelError &error) {
    EXPECT_STREQ(error.what(),
                 "A breaking change cannot bump the minor number of version "
                 "1.2.0: the `breaking` level must be `major`");
  }
}

// Breaking level: patch (0.0.x prototyping)

TEST(JSS_bump, breaking_patch_major) {
  EXPECT_EQ(bump(SemVer::Major, "0.0.4", Breaking::Patch), "0.0.5");
}

TEST(JSS_bump, breaking_patch_minor) {
  EXPECT_EQ(bump(SemVer::Minor, "0.0.4", Breaking::Patch), "0.0.5");
}

TEST(JSS_bump, breaking_patch_patch) {
  EXPECT_EQ(bump(SemVer::Patch, "0.0.4", Breaking::Patch), "0.0.5");
}

TEST(JSS_bump, breaking_patch_equal) {
  EXPECT_EQ(bump(SemVer::Equal, "0.0.4", Breaking::Patch), "0.0.4");
}

TEST(JSS_bump, breaking_patch_zero_minor_error) {
  EXPECT_THROW(bump(SemVer::Major, "0.1.0", Breaking::Patch),
               octue::jss::BreakingLevelError);
  EXPECT_THROW(bump(SemVer::Patch, "0.1.3", Breaking::Patch),
               octue::jss::BreakingLevelError);
}

TEST(JSS_bump, breaking_patch_stable_error) {
  EXPECT_THROW(bump(SemVer::Major, "1.0.0", Breaking::Patch),
               octue::jss::BreakingLevelError);
}

TEST(JSS_bump, breaking_patch_zero_minor_pre_release_error) {
  EXPECT_THROW(bump(SemVer::Major, "0.1.0-rc.1", Breaking::Patch),
               octue::jss::BreakingLevelError);
}

TEST(JSS_bump, breaking_patch_zero_minor_error_message) {
  try {
    bump(SemVer::Major, "0.1.3", Breaking::Patch);
    FAIL();
  } catch (const octue::jss::BreakingLevelError &error) {
    EXPECT_STREQ(error.what(),
                 "A breaking change cannot bump the patch number of version "
                 "0.1.3: the `breaking` level must be `minor` or `major`");
  }
}

TEST(JSS_bump, breaking_patch_stable_error_message) {
  try {
    bump(SemVer::Major, "2.0.0", Breaking::Patch);
    FAIL();
  } catch (const octue::jss::BreakingLevelError &error) {
    EXPECT_STREQ(error.what(),
                 "A breaking change cannot bump the patch number of version "
                 "2.0.0: the `breaking` level must be `major`");
  }
}

// Pre-releases. The expectations come from running `bump_prerelease` of the
// `semver` Python package (3.0.4) on the same inputs

TEST(JSS_bump, pre_release_major) {
  EXPECT_EQ(bump(SemVer::Major, "2.3.1-rc0"), "2.3.1-rc1");
}

TEST(JSS_bump, pre_release_minor) {
  EXPECT_EQ(bump(SemVer::Minor, "2.3.1-rc0"), "2.3.1-rc1");
}

TEST(JSS_bump, pre_release_patch) {
  EXPECT_EQ(bump(SemVer::Patch, "2.3.1-rc0"), "2.3.1-rc1");
}

TEST(JSS_bump, pre_release_equal) {
  EXPECT_EQ(bump(SemVer::Equal, "2.3.1-rc0"), "2.3.1-rc1");
}

TEST(JSS_bump, pre_release_zero_with_breaking_levels) {
  EXPECT_EQ(bump(SemVer::Major, "0.3.0-rc.1", Breaking::Minor), "0.3.0-rc.2");
  EXPECT_EQ(bump(SemVer::Major, "0.0.3-rc.1", Breaking::Patch), "0.0.3-rc.2");
}

TEST(JSS_bump, pre_release_dotted) {
  EXPECT_EQ(bump(SemVer::Patch, "2.3.1-rc.1"), "2.3.1-rc.2");
}

TEST(JSS_bump, pre_release_carry) {
  EXPECT_EQ(bump(SemVer::Patch, "1.0.0-rc9"), "1.0.0-rc10");
  EXPECT_EQ(bump(SemVer::Patch, "1.0.0-rc99"), "1.0.0-rc100");
}

TEST(JSS_bump, pre_release_leading_zero) {
  EXPECT_EQ(bump(SemVer::Patch, "1.0.0-rc09"), "1.0.0-rc10");
  EXPECT_EQ(bump(SemVer::Patch, "1.0.0-rc007"), "1.0.0-rc008");
}

TEST(JSS_bump, pre_release_without_number) {
  EXPECT_EQ(bump(SemVer::Patch, "1.0.0-alpha"), "1.0.0-alpha");
  EXPECT_EQ(bump(SemVer::Patch, "1.0.0-x-y-z"), "1.0.0-x-y-z");
}

TEST(JSS_bump, pre_release_number_in_the_middle) {
  EXPECT_EQ(bump(SemVer::Patch, "1.0.0-alpha.1.beta"), "1.0.0-alpha.2.beta");
}

TEST(JSS_bump, pre_release_last_of_many_numbers) {
  EXPECT_EQ(bump(SemVer::Patch, "1.0.0-a1b2"), "1.0.0-a1b3");
  EXPECT_EQ(bump(SemVer::Patch, "1.0.0-0.3.7"), "1.0.0-0.3.8");
}

TEST(JSS_bump, pre_release_numeric_only) {
  EXPECT_EQ(bump(SemVer::Patch, "1.0.0-1"), "1.0.0-2");
}

TEST(JSS_bump, pre_release_drops_build_metadata) {
  EXPECT_EQ(bump(SemVer::Patch, "1.0.0-rc.1+build.5"), "1.0.0-rc.2");
}

// Build metadata and invalid versions

TEST(JSS_bump, build_metadata_dropped_on_change) {
  EXPECT_EQ(bump(SemVer::Patch, "1.2.3+build.5"), "1.2.4");
}

TEST(JSS_bump, build_metadata_kept_on_equal) {
  EXPECT_EQ(bump(SemVer::Equal, "1.2.3+build.5"), "1.2.3+build.5");
}

TEST(JSS_bump, invalid_version) {
  EXPECT_THROW(bump(SemVer::Patch, "foo"), octue::jss::InvalidVersionError);
  EXPECT_THROW(bump(SemVer::Patch, "1.2"), octue::jss::InvalidVersionError);
  EXPECT_THROW(bump(SemVer::Patch, "v1.2.3"), octue::jss::InvalidVersionError);
  EXPECT_THROW(bump(SemVer::Patch, ""), octue::jss::InvalidVersionError);
}

TEST(JSS_bump, invalid_version_message) {
  try {
    bump(SemVer::Patch, "1.2");
    FAIL();
  } catch (const octue::jss::InvalidVersionError &error) {
    EXPECT_STREQ(error.what(), "Not a valid semantic version: 1.2");
  }
}

// Suggestions

TEST(JSS_suggest, initial_default) {
  const auto result{suggest(std::nullopt, SCHEMA_BASE)};
  EXPECT_EQ(result.change, Change::Initial);
  EXPECT_EQ(result.version, "0.0.1");
  EXPECT_TRUE(result.traces.empty());
}

TEST(JSS_suggest, initial_ignores_base_version_and_breaking) {
  const auto result{
      suggest(std::nullopt, SCHEMA_BASE, "3.2.1", Breaking::Patch)};
  EXPECT_EQ(result.change, Change::Initial);
  EXPECT_EQ(result.version, "0.0.1");
}

TEST(JSS_suggest, initial_custom) {
  const auto result{suggest(std::nullopt, SCHEMA_BASE, std::nullopt,
                            Breaking::Major, "0.1.0")};
  EXPECT_EQ(result.change, Change::Initial);
  EXPECT_EQ(result.version, "0.1.0");
}

TEST(JSS_suggest, initial_invalid) {
  EXPECT_THROW(suggest(std::nullopt, SCHEMA_BASE, std::nullopt, Breaking::Major,
                       "first"),
               octue::jss::InvalidVersionError);
}

TEST(JSS_suggest, no_base_version) {
  const auto result{suggest(SCHEMA_BASE, SCHEMA_MINOR)};
  EXPECT_EQ(result.change, Change::Minor);
  EXPECT_FALSE(result.version.has_value());
  EXPECT_EQ(result.traces.size(), 1);
}

TEST(JSS_suggest, equal) {
  const auto result{suggest(SCHEMA_BASE, SCHEMA_BASE, "0.1.9")};
  EXPECT_EQ(result.change, Change::Equal);
  EXPECT_EQ(result.version, "0.1.9");
  EXPECT_TRUE(result.traces.empty());
}

TEST(JSS_suggest, equal_pre_release) {
  const auto result{suggest(SCHEMA_BASE, SCHEMA_BASE, "2.3.1-rc0")};
  EXPECT_EQ(result.change, Change::Equal);
  EXPECT_EQ(result.version, "2.3.1-rc1");
}

TEST(JSS_suggest, patch) {
  const auto result{suggest(SCHEMA_BASE, SCHEMA_PATCH, "2.3.1")};
  EXPECT_EQ(result.change, Change::Patch);
  EXPECT_EQ(result.version, "2.3.2");
  EXPECT_TRUE(result.traces.empty());
}

TEST(JSS_suggest, minor) {
  const auto result{suggest(SCHEMA_BASE, SCHEMA_MINOR, "2.3.1")};
  EXPECT_EQ(result.change, Change::Minor);
  EXPECT_EQ(result.version, "2.4.0");
  EXPECT_EQ(result.traces.size(), 1);
}

TEST(JSS_suggest, major) {
  const auto result{suggest(SCHEMA_BASE, SCHEMA_MAJOR, "2.3.1")};
  EXPECT_EQ(result.change, Change::Major);
  EXPECT_EQ(result.version, "3.0.0");
  EXPECT_FALSE(result.traces.empty());
}

TEST(JSS_suggest, major_breaking_minor) {
  const auto result{
      suggest(SCHEMA_BASE, SCHEMA_MAJOR, "0.3.1", Breaking::Minor)};
  EXPECT_EQ(result.change, Change::Major);
  EXPECT_EQ(result.version, "0.4.0");
}

TEST(JSS_suggest, major_breaking_patch) {
  const auto result{
      suggest(SCHEMA_BASE, SCHEMA_MAJOR, "0.0.3", Breaking::Patch)};
  EXPECT_EQ(result.change, Change::Major);
  EXPECT_EQ(result.version, "0.0.4");
}

TEST(JSS_suggest, breaking_level_error) {
  EXPECT_THROW(suggest(SCHEMA_BASE, SCHEMA_MAJOR, "0.1.3", Breaking::Patch),
               octue::jss::BreakingLevelError);
}

TEST(JSS_suggest, invalid_base_version) {
  EXPECT_THROW(suggest(SCHEMA_BASE, SCHEMA_MAJOR, "latest"),
               octue::jss::InvalidVersionError);
}

TEST(JSS_suggest, unknown) {
  const auto to{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema",
    "const": "foo"
  })JSON")};

  const auto result{suggest(SCHEMA_UNKNOWN_FROM, to, "1.0.0")};
  EXPECT_FALSE(result.change.has_value());
  EXPECT_FALSE(result.version.has_value());
  EXPECT_EQ(result.traces.size(), 1);
}

// Names

TEST(JSS_suggest, to_string) {
  EXPECT_EQ(octue::jss::to_string(Change::Initial), "initial");
  EXPECT_EQ(octue::jss::to_string(Change::Equal), "equal");
  EXPECT_EQ(octue::jss::to_string(SemVer::Major), "major");
  EXPECT_EQ(octue::jss::to_string(Breaking::Patch), "patch");
  EXPECT_EQ(octue::jss::to_string(octue::jss::Compatibility::Incompatible),
            "incompatible");
}

TEST(JSS_suggest, to_breaking) {
  EXPECT_EQ(octue::jss::to_breaking("major"), Breaking::Major);
  EXPECT_EQ(octue::jss::to_breaking("minor"), Breaking::Minor);
  EXPECT_EQ(octue::jss::to_breaking("patch"), Breaking::Patch);
  EXPECT_FALSE(octue::jss::to_breaking("Major").has_value());
  EXPECT_FALSE(octue::jss::to_breaking("").has_value());
}
