#include "array/lc_34_find_positions.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class FindPositionsTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new FindPositions(); }

  void TearDown() override { delete exec; }

 protected:
  FindPositions* exec{nullptr};
};

TEST_F(FindPositionsTest, SearchInsert1) {
  std::vector<int> nums1 = {5, 7, 7, 8, 8, 10};
  int target1 = 8;
  std::vector<int> res1 = exec->searchRange1(nums1, target1);
  ASSERT_EQ(3, res1.at(0));
  ASSERT_EQ(4, res1.at(1));

  std::vector<int> nums2 = {5, 7, 7, 8, 8, 10};
  int target2 = 6;
  std::vector<int> res2 = exec->searchRange1(nums2, target2);
  ASSERT_EQ(-1, res2.at(0));
  ASSERT_EQ(-1, res2.at(1));

  std::vector<int> nums3 = {};
  int target3 = 0;
  std::vector<int> res3 = exec->searchRange1(nums3, target3);
  ASSERT_EQ(-1, res3.at(0));
  ASSERT_EQ(-1, res3.at(1));
};

TEST_F(FindPositionsTest, SearchInsert2) {
  std::vector<int> nums1 = {5, 7, 7, 8, 8, 10};
  int target1 = 8;
  std::vector<int> res1 = exec->searchRange2(nums1, target1);
  ASSERT_EQ(3, res1.at(0));
  ASSERT_EQ(4, res1.at(1));

  std::vector<int> nums2 = {5, 7, 7, 8, 8, 10};
  int target2 = 6;
  std::vector<int> res2 = exec->searchRange2(nums2, target2);
  ASSERT_EQ(-1, res2.at(0));
  ASSERT_EQ(-1, res2.at(1));

  std::vector<int> nums3 = {};
  int target3 = 0;
  std::vector<int> res3 = exec->searchRange2(nums3, target3);
  ASSERT_EQ(-1, res3.at(0));
  ASSERT_EQ(-1, res3.at(1));
};
}  // namespace array
}  // namespace algo