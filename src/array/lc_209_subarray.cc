#include "array/lc_209_subarray.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class SearchInsertPositionTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MinSubArrayLen(); }

  void TearDown() override { delete exec; }

 protected:
  MinSubArrayLen* exec{nullptr};
};

TEST_F(SearchInsertPositionTest, minSubArrayLen1) {
  std::vector<int> nums1 = {2, 3, 1, 2, 4, 3};
  int target1 = 7;
  ASSERT_EQ(2, exec->minSubArrayLen1(nums1, target1));

  std::vector<int> nums2 = {1, 4, 4};
  int target2 = 4;
  ASSERT_EQ(1, exec->minSubArrayLen1(nums2, target2));

  std::vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
  int target3 = 11;
  ASSERT_EQ(0, exec->minSubArrayLen1(nums3, target3));

  std::vector<int> nums4 = {1, 2, 3, 4, 5};
  int target4 = 11;
  ASSERT_EQ(3, exec->minSubArrayLen1(nums4, target4));
}

TEST_F(SearchInsertPositionTest, minSubArrayLen2) {
  std::vector<int> nums1 = {2, 3, 1, 2, 4, 3};
  int target1 = 7;
  ASSERT_EQ(2, exec->minSubArrayLen2(nums1, target1));

  std::vector<int> nums2 = {1, 4, 4};
  int target2 = 4;
  ASSERT_EQ(1, exec->minSubArrayLen2(nums2, target2));

  std::vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
  int target3 = 11;
  ASSERT_EQ(0, exec->minSubArrayLen2(nums3, target3));

  std::vector<int> nums4 = {1, 2, 3, 4, 5};
  int target4 = 11;
  ASSERT_EQ(3, exec->minSubArrayLen2(nums4, target4));
}
}  // namespace array
}  // namespace algo