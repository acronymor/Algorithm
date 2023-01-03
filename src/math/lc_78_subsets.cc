#include "math/lc_78_subsets.h"

#include "gtest/gtest.h"

namespace algo {
namespace math {
class SubsetsTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new Subsets(); }

  void TearDown() override { delete exec; }

 protected:
  Subsets* exec{nullptr};
};

TEST_F(SubsetsTest, combine) {
  std::vector<int> nums1 = {1, 2, 3};
  std::vector<std::vector<int>> res1 = exec->subsets(nums1);
  ASSERT_EQ(0, res1[0].size());
  ASSERT_EQ(1, res1[1][0]);
  ASSERT_EQ(3, res1[6][1]);
  ASSERT_EQ(3, res1[7][0]);

  std::vector<int> nums2 = {0};
  std::vector<std::vector<int>> res2 = exec->subsets(nums2);
  ASSERT_EQ(0, res2[0].size());
  ASSERT_EQ(0, res2[1][0]);
}

}  // namespace math
}  // namespace algo
