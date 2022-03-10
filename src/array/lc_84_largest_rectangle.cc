#include "array/lc_84_largest_rectangle.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class LargestRectangleAreaTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new LargestRectangleArea(); }

  void TearDown() override { delete exec; }

 protected:
  LargestRectangleArea* exec{nullptr};
};

TEST_F(LargestRectangleAreaTest, largestRectangleArea1) {
  std::vector<int> nums1 = {2, 1, 5, 6, 2, 3};
  ASSERT_EQ(10, exec->largestRectangleArea1(nums1));

  std::vector<int> nums2 = {2, 4};
  ASSERT_EQ(4, exec->largestRectangleArea1(nums2));

  std::vector<int> nums3 = {1, 2, 4, 6};
  ASSERT_EQ(8, exec->largestRectangleArea1(nums3));

  std::vector<int> nums4 = {6, 4, 2, 1};
  ASSERT_EQ(8, exec->largestRectangleArea1(nums4));

  std::vector<int> nums5 = {1, 1};
  ASSERT_EQ(2, exec->largestRectangleArea1(nums5));

  std::vector<int> nums6 = {2, 0, 2};
  ASSERT_EQ(2, exec->largestRectangleArea1(nums6));
}

TEST_F(LargestRectangleAreaTest, largestRectangleArea2) {
  std::vector<int> nums1 = {2, 1, 5, 6, 2, 3};
  ASSERT_EQ(10, exec->largestRectangleArea2(nums1));

  std::vector<int> nums2 = {2, 4};
  ASSERT_EQ(4, exec->largestRectangleArea2(nums2));

  std::vector<int> nums3 = {1, 2, 4, 6};
  ASSERT_EQ(8, exec->largestRectangleArea2(nums3));

  std::vector<int> nums4 = {6, 4, 2, 1};
  ASSERT_EQ(8, exec->largestRectangleArea2(nums4));

  std::vector<int> nums5 = {1, 1};
  ASSERT_EQ(2, exec->largestRectangleArea2(nums5));

  std::vector<int> nums6 = {2, 0, 2};
  ASSERT_EQ(2, exec->largestRectangleArea2(nums6));
}

TEST_F(LargestRectangleAreaTest, largestRectangleArea3) {
  std::vector<int> nums1 = {2, 1, 5, 6, 2, 3};
  ASSERT_EQ(10, exec->largestRectangleArea3(nums1));

  std::vector<int> nums2 = {2, 4};
  ASSERT_EQ(4, exec->largestRectangleArea3(nums2));

  std::vector<int> nums3 = {1, 2, 4, 6};
  ASSERT_EQ(8, exec->largestRectangleArea3(nums3));

  std::vector<int> nums4 = {6, 4, 2, 1};
  ASSERT_EQ(8, exec->largestRectangleArea3(nums4));

  std::vector<int> nums5 = {1, 1};
  ASSERT_EQ(2, exec->largestRectangleArea3(nums5));

  std::vector<int> nums6 = {2, 0, 2};
  ASSERT_EQ(2, exec->largestRectangleArea3(nums6));
}
}  // namespace array
}  // namespace algo