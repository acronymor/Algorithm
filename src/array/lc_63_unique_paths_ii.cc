#include "array/lc_63_unique_paths_ii.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class UniquePathsIITest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new UniquePathsII(); }

  void TearDown() override { delete exec; }

 protected:
  UniquePathsII* exec{nullptr};
};

TEST_F(UniquePathsIITest, uniquePaths) {
  std::vector<std::vector<int>> nums1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  ASSERT_EQ(2, exec->uniquePaths(nums1));

  std::vector<std::vector<int>> nums2 = {{0, 1}, {0, 0}};
  ASSERT_EQ(1, exec->uniquePaths(nums2));

  std::vector<std::vector<int>> nums3 = {{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
  ASSERT_EQ(7, exec->uniquePaths(nums3));
};
}  // namespace array
};  // namespace algo
