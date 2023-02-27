#include "array/lc_1144_decrease_elements.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class MovesToMakeZigzagTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MovesToMakeZigzag(); }

  void TearDown() override { delete exec; }

 protected:
  MovesToMakeZigzag* exec{nullptr};
};

TEST_F(MovesToMakeZigzagTest, sortedSquares) {
  std::vector<int> nums1 = {1, 2, 3};
  int res1 = exec->solve(nums1);
  ASSERT_EQ(2, res1);

  std::vector<int> nums2 = {9, 6, 1, 6, 2};
  int res2 = exec->solve(nums2);
  ASSERT_EQ(4, res2);
}
}  // namespace array
}  // namespace algo
