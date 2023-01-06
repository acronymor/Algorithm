#include "array/lc_51_n_queens.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class NQueensTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new NQueens(); }

  void TearDown() override { delete exec; }

 protected:
  NQueens* exec{nullptr};
};

TEST_F(NQueensTest, permute) {
  std::vector<std::vector<std::string>> res1 = exec->solve(4);
  ASSERT_EQ(2, res1.size());
  ASSERT_EQ(".Q..", res1[0][0]);
  ASSERT_EQ("...Q", res1[0][1]);
  ASSERT_EQ("Q...", res1[0][2]);
  ASSERT_EQ("..Q.", res1[0][3]);

  std::vector<std::vector<std::string>> res2 = exec->solve(1);
  ASSERT_EQ(1, res2.size());
  ASSERT_EQ("Q", res2[0][0]);
}

}  // namespace array
}  // namespace algo
