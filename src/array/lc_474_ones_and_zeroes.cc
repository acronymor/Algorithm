#include "array/lc_474_ones_and_zeroes.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class FindMaxFormTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new FindMaxForm(); }

  void TearDown() override { delete exec; }

 protected:
  FindMaxForm* exec{nullptr};
};

TEST_F(FindMaxFormTest, solve) {
  std::vector<std::string> nums1 = {"10", "0001", "111001", "1", "0"};
  ASSERT_EQ(4, exec->solve(nums1, 5, 3));

  std::vector<std::string> nums2 = {"10", "0", "1"};
  ASSERT_EQ(2, exec->solve(nums2, 1, 1));
}
}  // namespace array
}  // namespace algo
