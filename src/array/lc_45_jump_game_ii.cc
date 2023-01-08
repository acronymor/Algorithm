#include "array/lc_45_jump_game_ii.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class CanJumpIITest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new CanJumpII(); }

  void TearDown() override { delete exec; }

 protected:
  CanJumpII* exec{nullptr};
};

TEST_F(CanJumpIITest, jump) {
  std::vector<int> nums1 = {2, 3, 1, 1, 4};
  ASSERT_EQ(2, exec->jump(nums1));

  std::vector<int> nums2 = {2, 3, 0, 1, 4};
  ASSERT_EQ(2, exec->jump(nums2));

  std::vector<int> nums3 = {0};
  ASSERT_EQ(0, exec->jump(nums3));
}
}  // namespace array
}  // namespace algo
