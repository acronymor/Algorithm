#include "array/lc_977_sorted_squares.h"
#include "gtest/gtest.h"

namespace algo {
namespace array {
class SortedSquaresTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new SortedSquares(); }

  void TearDown() override { delete exec; }

 protected:
  SortedSquares* exec{nullptr};
};

TEST_F(SortedSquaresTest, sortedSquares) {
  std::vector<int> nums1 = {-4, -1, 0, 3, 10};
  std::vector<int> res1 = exec->sortedSquares(nums1);
  ASSERT_EQ(0, res1.at(0));
  ASSERT_EQ(1, res1.at(1));
  ASSERT_EQ(9, res1.at(2));
  ASSERT_EQ(16, res1.at(3));
  ASSERT_EQ(100, res1.at(4));

  std::vector<int> nums2 = {-7, -3, 2, 3, 11};
  std::vector<int> res2 = exec->sortedSquares(nums2);
  ASSERT_EQ(4, res2.at(0));
  ASSERT_EQ(9, res2.at(1));
  ASSERT_EQ(9, res2.at(2));
  ASSERT_EQ(49, res2.at(3));
  ASSERT_EQ(121, res2.at(4));
}
}  // namespace array
}  // namespace algo