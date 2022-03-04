#include "array/lc_283_move_zeroes.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class MoveZeroesTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MoveZeroes(); }

  void TearDown() override { delete exec; }

 protected:
  MoveZeroes* exec{nullptr};
};

TEST_F(MoveZeroesTest, RemoveElement) {
  std::vector<int> nums1 = {0, 1, 0, 3, 12};
  exec->moveZeroes(nums1);
  ASSERT_EQ(1, nums1.at(0));
  ASSERT_EQ(3, nums1.at(1));
  ASSERT_EQ(12, nums1.at(2));
  ASSERT_EQ(0, nums1.at(3));
  ASSERT_EQ(0, nums1.at(4));

  std::vector<int> nums2 = {0};
  exec->moveZeroes(nums2);
  ASSERT_EQ(0, nums2.at(0));
};
}  // namespace array
};  // namespace algo