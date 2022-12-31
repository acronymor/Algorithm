#include "math/lc_77_combinations.h"

#include "gtest/gtest.h"

namespace algo {
namespace math {
class CombineTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new Combine(); }

  void TearDown() override { delete exec; }

 protected:
  Combine* exec{nullptr};
};

TEST_F(CombineTest, combine) {
  std::vector<std::vector<int>> res1 = exec->combine(4, 2);
  ASSERT_EQ(1, res1[0][0]);
  ASSERT_EQ(2, res1[0][1]);
  ASSERT_EQ(3, res1[5][0]);
  ASSERT_EQ(4, res1[5][1]);

  std::vector<std::vector<int>> res2 = exec->combine(1, 1);
  ASSERT_EQ(1, res1[0][0]);
}

}  // namespace math
}  // namespace algo
