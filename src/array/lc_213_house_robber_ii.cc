#include "array/lc_213_house_robber_ii.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class RobIITest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new RobII(); }

  void TearDown() override { delete exec; }

 protected:
  RobII* exec{nullptr};
};

TEST_F(RobIITest, solve) {
  std::vector<int> nums1 = {2, 3, 2};
  ASSERT_EQ(3, exec->solve(nums1));

  std::vector<int> nums2 = {1, 2, 3, 1};
  ASSERT_EQ(4, exec->solve(nums2));
}
}  // namespace array
}  // namespace algo