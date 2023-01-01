#include "math/lc_216_combination_sum_iii.h"

#include "gtest/gtest.h"

namespace algo {
namespace math {
class CombineSumIIITest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new CombineSumIII(); }

  void TearDown() override { delete exec; }

 protected:
  CombineSumIII* exec{nullptr};
};

TEST_F(CombineSumIIITest, combine) {
  std::vector<std::vector<int>> res1 = exec->combineSum(7, 3);
  ASSERT_EQ(1, res1[0][0]);
  ASSERT_EQ(2, res1[0][1]);
  ASSERT_EQ(4, res1[0][2]);

  std::vector<std::vector<int>> res2 = exec->combineSum(9, 3);
  ASSERT_EQ(1, res2[0][0]);
  ASSERT_EQ(2, res2[0][1]);
  ASSERT_EQ(6, res2[0][2]);
}

}  // namespace math
}  // namespace algo
