#include "array/lc_349_intersection_of_two_arrays.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class IntersectionTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new Intersection(); }

  void TearDown() override { delete exec; }

 protected:
  Intersection* exec{nullptr};
};

TEST_F(IntersectionTest, intersection1) {
  std::vector<int> nums1 = {1, 2, 2, 1};
  std::vector<int> nums2 = {2, 2};
  std::vector<int> res1 = exec->intersection1(nums1, nums2);
  ASSERT_EQ(2, res1.at(0));

  std::vector<int> nums3 = {4, 9, 5};
  std::vector<int> nums4 = {9, 4, 9, 8, 4};
  std::vector<int> res2 = exec->intersection1(nums3, nums4);
  ASSERT_EQ(9, res2.at(0));
  ASSERT_EQ(4, res2.at(1));
}

TEST_F(IntersectionTest, intersection2) {
  std::vector<int> nums1 = {1, 2, 2, 1};
  std::vector<int> nums2 = {2, 2};
  std::vector<int> res1 = exec->intersection2(nums1, nums2);
  ASSERT_EQ(2, res1.at(0));

  std::vector<int> nums3 = {4, 9, 5};
  std::vector<int> nums4 = {9, 4, 9, 8, 4};
  std::vector<int> res2 = exec->intersection2(nums3, nums4);
  ASSERT_EQ(9, res2.at(0));
  ASSERT_EQ(4, res2.at(1));
}
}  // namespace array
}  // namespace algo
