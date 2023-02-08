#include "array/lc_198_house_robber.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class RobTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new Rob(); }

  void TearDown() override { delete exec; }

 protected:
  Rob* exec{nullptr};
};

TEST_F(RobTest, solve) {
  std::vector<int> nums1 = {1, 2, 3, 1};
  ASSERT_EQ(4, exec->solve(nums1));

  std::vector<int> nums2 = {2, 7, 9, 3, 1};
  ASSERT_EQ(12, exec->solve(nums2));
}
}  // namespace array
}  // namespace algo