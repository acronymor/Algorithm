#include "array/lc_35_search_insert_position.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class SearchInsertPositionTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new SearchInsertPosition(); }

  void TearDown() override { delete exec; }

 protected:
  SearchInsertPosition* exec{nullptr};
};

TEST_F(SearchInsertPositionTest, SearchInsert1) {
  std::vector<int> nums1 = {1, 3, 5, 6};
  int target1 = 5;
  ASSERT_EQ(2, exec->searchInsert1(nums1, target1));

  std::vector<int> nums2 = {1, 3, 5, 6};
  int target2 = 2;
  ASSERT_EQ(1, exec->searchInsert1(nums2, target2));

  std::vector<int> nums3 = {1, 3, 5, 6};
  int target3 = 7;
  ASSERT_EQ(4, exec->searchInsert1(nums3, target3));
}

TEST_F(SearchInsertPositionTest, SearchInsert2) {
  std::vector<int> nums1 = {1, 3, 5, 6};
  int target1 = 5;
  ASSERT_EQ(2, exec->searchInsert2(nums1, target1));

  std::vector<int> nums2 = {1, 3, 5, 6};
  int target2 = 2;
  ASSERT_EQ(1, exec->searchInsert2(nums2, target2));

  std::vector<int> nums3 = {1, 3, 5, 6};
  int target3 = 7;
  ASSERT_EQ(4, exec->searchInsert2(nums3, target3));
}
}  // namespace array
}  // namespace algo