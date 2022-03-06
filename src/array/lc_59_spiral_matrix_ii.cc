#include "array/lc_59_spiral_matrix_ii.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class SpiralOrderIITest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new SpiralOrderII(); }

  void TearDown() override { delete exec; }

 protected:
  SpiralOrderII* exec{nullptr};
};

TEST_F(SpiralOrderIITest, spiralOrder) {
  int num1 = 3;
  std::vector<std::vector<int>> res1 = exec->spiralOrder(num1);
  ASSERT_EQ(1, res1[0][0]);
  ASSERT_EQ(3, res1[0][2]);
  ASSERT_EQ(9, res1[1][1]);
  ASSERT_EQ(5, res1[2][2]);

  int num2 = 1;
  std::vector<std::vector<int>> res2 = exec->spiralOrder(num2);
  ASSERT_EQ(1, res2[0][0]);
}
}  // namespace array
}  // namespace algo