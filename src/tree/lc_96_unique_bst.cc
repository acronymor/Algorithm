#include "tree/lc_96_unique_bst.h"

#include "gtest/gtest.h"

namespace algo {
namespace tree {
class NumTreesTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new NumTrees(); }

  void TearDown() override { delete exec; }

 protected:
  NumTrees* exec{nullptr};
};

TEST_F(NumTreesTest, numTrees) {
  ASSERT_EQ(5, exec->numTrees(3));
  ASSERT_EQ(1, exec->numTrees(1));
}
}  // namespace tree
}  // namespace algo
