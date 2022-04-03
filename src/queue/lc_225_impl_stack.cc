#include "queue/lc_225_impl_stack.h"

#include "gtest/gtest.h"

namespace algo {
namespace queue {
class MyStackTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MyStack(); }

  void TearDown() override { delete exec; }

 protected:
  MyStack* exec{nullptr};
};

TEST_F(MyStackTest, MyStack) {
  exec->push(1);
  exec->push(2);
  int res1 = exec->top();
  ASSERT_EQ(2, res1);
  res1 = exec->pop();
  ASSERT_EQ(2, res1);
  ASSERT_FALSE(exec->empty());
}
}  // namespace queue
}  // namespace algo