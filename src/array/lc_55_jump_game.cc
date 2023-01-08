#include "array/lc_55_jump_game.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class CanJumpTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new CanJump(); }

  void TearDown() override { delete exec; }

 protected:
  CanJump* exec{nullptr};
};

TEST_F(CanJumpTest, canJump1) {
  std::vector<int> nums1 = {2, 3, 1, 1, 4};
  ASSERT_TRUE(exec->canJump1(nums1));

  std::vector<int> nums2 = {3, 2, 1, 0, 4};
  ASSERT_FALSE(exec->canJump1(nums2));
}

TEST_F(CanJumpTest, canJump2) {
  std::vector<int> nums1 = {2, 3, 1, 1, 4};
  ASSERT_TRUE(exec->canJump2(nums1));

  std::vector<int> nums2 = {3, 2, 1, 0, 4};
  ASSERT_FALSE(exec->canJump2(nums2));
}
}  // namespace array
}  // namespace algo
