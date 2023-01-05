#include "math/lc_46_permutations.h"

#include "gtest/gtest.h"

namespace algo {
namespace math {
class PermuteTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new Permute(); }

  void TearDown() override { delete exec; }

 protected:
  Permute* exec{nullptr};
};

TEST_F(PermuteTest, permute) {
  std::vector<int> nums1 = {1, 2, 3};
  std::vector<std::vector<int>> res1 = exec->permute(nums1);
  ASSERT_EQ(1, res1[0][0]);
  ASSERT_EQ(2, res1[0][1]);
  ASSERT_EQ(3, res1[0][2]);

  std::vector<int> nums2 = {1};
  std::vector<std::vector<int>> res2 = exec->permute(nums2);
  ASSERT_EQ(1, res1[0][0]);
}

}  // namespace math
}  // namespace algo