#include "string/lc_115_num_distinct.h"

#include "gtest/gtest.h"

namespace algo {
namespace string {
class NumDistinctTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new NumDistinct(); }

  void TearDown() override { delete exec; }

 protected:
  NumDistinct* exec{nullptr};
};

TEST_F(NumDistinctTest, solve) {
  ASSERT_EQ(3, exec->solve("rabbbit", "rabbit"));
  ASSERT_EQ(5, exec->solve("babgbag", "bag"));
};
};  // namespace string
}  // namespace algo