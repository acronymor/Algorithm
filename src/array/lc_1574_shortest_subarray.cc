#include "array/lc_1574_shortest_subarray.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class FindLengthOfShortestSubnumsayTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new FindLengthOfShortestSubnumsay(); }

  void TearDown() override { delete exec; }

 protected:
  FindLengthOfShortestSubnumsay* exec{nullptr};
};

TEST_F(FindLengthOfShortestSubnumsayTest, solve) {
  std::vector<int> nums1 = {1, 2, 3, 10, 4, 2, 3, 5};
  int res1 = exec->solve(nums1);
  ASSERT_EQ(3, res1);

  std::vector<int> nums2 = {5, 4, 3, 2, 1};
  int res2 = exec->solve(nums2);
  ASSERT_EQ(4, res2);

  std::vector<int> nums3 = {1, 2, 3};
  int res3 = exec->solve(nums3);
  ASSERT_EQ(0, res3);

  std::vector<int> nums4 = {1};
  int res4 = exec->solve(nums4);
  ASSERT_EQ(0, res4);

  std::vector<int> nums5 = {1, 2, 3, 3, 10, 1, 3, 3, 5};
  int res5 = exec->solve(nums5);
  ASSERT_EQ(2, res5);
}
}  // namespace array
}  // namespace algo