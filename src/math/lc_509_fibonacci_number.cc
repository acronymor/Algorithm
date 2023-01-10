#include "math/lc_509_fibonacci_number.h"

#include "gtest/gtest.h"

namespace algo {
namespace math {
class FibTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new Fib(); }

  void TearDown() override { delete exec; }

 protected:
  Fib* exec{nullptr};
};

TEST_F(FibTest, fib1) {
  ASSERT_EQ(1, exec->fib1(2));
  ASSERT_EQ(2, exec->fib1(3));
  ASSERT_EQ(3, exec->fib1(4));
}

TEST_F(FibTest, fib2) {
  ASSERT_EQ(1, exec->fib2(2));
  ASSERT_EQ(2, exec->fib2(3));
  ASSERT_EQ(3, exec->fib2(4));
}
}  // namespace math
}  // namespace algo
