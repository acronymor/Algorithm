#include "array/lc_455_assign_cookies.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class AssignCookiesTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new AssignCookies(); }

  void TearDown() override { delete exec; }

 protected:
  AssignCookies* exec{nullptr};
};

TEST_F(AssignCookiesTest, solve1) {
  std::vector<int> g1 = {1, 2, 3};
  std::vector<int> s1 = {1, 1};
  ASSERT_EQ(1, exec->solve(g1, s1));

  std::vector<int> g2 = {1, 2};
  std::vector<int> s2 = {1, 2, 3};
  ASSERT_EQ(2, exec->solve(g2, s2));
};
}  // namespace array
}  // namespace algo
