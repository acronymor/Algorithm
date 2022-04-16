#include "array/lc_150_reverse_polish_notation.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class EvalRPNTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new EvalRPN(); }

  void TearDown() override { delete exec; }

 protected:
  EvalRPN* exec{nullptr};
};

TEST_F(EvalRPNTest, evalRPN) {
  std::vector<std::string> tokens1 = {"2", "1", "+", "3", "*"};
  ASSERT_EQ(9, exec->evalRPN(tokens1));

  std::vector<std::string> tokens2 = {"4", "13", "5", "/", "+"};
  ASSERT_EQ(6, exec->evalRPN(tokens2));

  std::vector<std::string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
  ASSERT_EQ(22, exec->evalRPN(tokens3));
}
}  // namespace array
}  // namespace algo