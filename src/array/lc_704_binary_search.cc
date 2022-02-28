#include "array/lc_704_binary_search.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class BinarySearchTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new BinarySearch(); }

  void TearDown() override { delete exec; }

 protected:
  BinarySearch* exec{nullptr};
};

TEST_F(BinarySearchTest, Search1) {
  std::vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
  int target1 = 9;
  ASSERT_EQ(4, exec->search1(nums1, target1));

  std::vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
  int target2 = 2;
  ASSERT_EQ(-1, exec->search1(nums2, target2));

  std::vector<int> nums3 = {5};
  int target3 = 5;
  ASSERT_EQ(0, exec->search1(nums3, target3));
};

TEST_F(BinarySearchTest, Search2) {
  std::vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
  int target1 = 9;
  ASSERT_EQ(4, exec->search2(nums1, target1));

  std::vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
  int target2 = 2;
  ASSERT_EQ(-1, exec->search2(nums2, target2));

  std::vector<int> nums3 = {5};
  int target3 = 5;
  ASSERT_EQ(0, exec->search2(nums3, target3));
};
}  // namespace array
}  // namespace algo