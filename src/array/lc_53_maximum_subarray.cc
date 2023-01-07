#include "array/lc_53_maximum_subarray.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class MaxSubArrayTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MaxSubArray(); }

  void TearDown() override { delete exec; }

 protected:
  MaxSubArray* exec{nullptr};
};

TEST_F(MaxSubArrayTest, maxSubArray1) {
  std::vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  ASSERT_EQ(6, exec->maxSubArray1(nums1));

  std::vector<int> nums2 = {1};
  ASSERT_EQ(1, exec->maxSubArray1(nums2));

  std::vector<int> nums3 = {5, 4, -1, 7, 8};
  ASSERT_EQ(23, exec->maxSubArray1(nums3));
};

TEST_F(MaxSubArrayTest, maxSubArray2) {
  std::vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  ASSERT_EQ(6, exec->maxSubArray2(nums1));

  std::vector<int> nums2 = {1};
  ASSERT_EQ(1, exec->maxSubArray2(nums2));

  std::vector<int> nums3 = {5, 4, -1, 7, 8};
  ASSERT_EQ(23, exec->maxSubArray2(nums3));
};
}  // namespace array
}  // namespace algo
