#include "array/lc_416_subset_sum.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class CanPartitionTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new CanPartition(); }

  void TearDown() override { delete exec; }

 protected:
  CanPartition* exec{nullptr};
};

TEST_F(CanPartitionTest, solve1) {
  std::vector<int> nums1 = {1, 5, 11, 5};
  ASSERT_TRUE(exec->solve1(nums1));

  std::vector<int> nums2 = {1, 2, 3, 5};
  ASSERT_FALSE(exec->solve1(nums2));
}

TEST_F(CanPartitionTest, solve2) {
  std::vector<int> nums1 = {1, 5, 11, 5};
  ASSERT_TRUE(exec->solve2(nums1));

  std::vector<int> nums2 = {1, 2, 3, 5};
  ASSERT_FALSE(exec->solve2(nums2));
}

}  // namespace array
}  // namespace algo
