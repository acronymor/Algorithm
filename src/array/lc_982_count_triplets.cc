#include "array/lc_982_count_triplets.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class CountTripletsTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new CountTriplets(); }

  void TearDown() override { delete exec; }

 protected:
  CountTriplets* exec{nullptr};
};

TEST_F(CountTripletsTest, solve1) {
  ASSERT_EQ(12, exec->solve1({2, 1, 3}));
  ASSERT_EQ(27, exec->solve1({0, 0, 0}));
};

TEST_F(CountTripletsTest, solve2) {
  ASSERT_EQ(12, exec->solve2({2, 1, 3}));
  ASSERT_EQ(27, exec->solve2({0, 0, 0}));
};

};  // namespace array
}  // namespace algo
