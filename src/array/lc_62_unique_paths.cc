#include "array/lc_62_unique_paths.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class UniquePathsTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new UniquePaths(); }

  void TearDown() override { delete exec; }

 protected:
  UniquePaths* exec{nullptr};
};

TEST_F(UniquePathsTest, uniquePaths) {
  ASSERT_EQ(28, exec->uniquePaths(3, 7));
  ASSERT_EQ(3, exec->uniquePaths(3, 2));
};
}  // namespace array
};  // namespace algo
