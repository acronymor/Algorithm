#include "math/lc_90_subsets_ii.h"

#include "gtest/gtest.h"

namespace algo {
namespace math {
class SubsetsIITest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new SubsetsII(); }

  void TearDown() override { delete exec; }

 protected:
  SubsetsII* exec{nullptr};
};

TEST_F(SubsetsIITest, combine) {
  std::vector<int> nums1 = {1, 2, 2};
  std::vector<std::vector<int>> res1 = exec->subsets(nums1);
  ASSERT_EQ(0, res1[0].size());
  ASSERT_EQ(1, res1[1][0]);
  ASSERT_EQ(2, res1[3][1]);
  ASSERT_EQ(2, res1[5][1]);

  std::vector<int> nums2 = {0};
  std::vector<std::vector<int>> res2 = exec->subsets(nums2);
  ASSERT_EQ(0, res2[0].size());
  ASSERT_EQ(0, res2[1][0]);
}

}  // namespace math
}  // namespace algo
