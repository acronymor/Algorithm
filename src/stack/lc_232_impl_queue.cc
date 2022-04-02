#include "stack/lc_232_impl_queue.h"

#include "gtest/gtest.h"

namespace algo {
namespace stack {
class MyQueueTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MyQueue(); }

  void TearDown() override { delete exec; }

 protected:
  MyQueue* exec{nullptr};
};

TEST_F(MyQueueTest, MyQueue) {
  exec->push(1);
  exec->push(2);
  int res1 = exec->peek();
  ASSERT_EQ(1, res1);
  res1 = exec->pop();
  ASSERT_EQ(1, res1);
  ASSERT_FALSE(exec->empty());
}
}  // namespace stack
}  // namespace algo