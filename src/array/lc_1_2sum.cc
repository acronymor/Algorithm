#include "array/lc_1_2sum.h"
#include "gtest/gtest.h"

namespace algo {
namespace array {
class TwoSumTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new TwoSum(); }

  void TearDown() override { delete exec; }

 protected:
  TwoSum* exec{nullptr};
};

TEST_F(TwoSumTest, twoSum) {
  std::vector<int> nums1 = {2, 7, 11, 15};
  std::vector<int> res1 = exec->twoSum(nums1, 9);
  ASSERT_EQ(0, res1.at(0));
  ASSERT_EQ(1, res1.at(1));

  std::vector<int> nums2 = {3, 2, 4};
  std::vector<int> res2 = exec->twoSum(nums2, 6);
  ASSERT_EQ(1, res2.at(0));
  ASSERT_EQ(2, res2.at(1));

  std::vector<int> nums3 = {3, 3};
  std::vector<int> res3 = exec->twoSum(nums3, 6);
  ASSERT_EQ(0, res3.at(0));
  ASSERT_EQ(1, res3.at(1));
}
}  // namespace array
}  // namespace algo
