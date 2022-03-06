#include "array/lc_54_spiral_matrix.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class SpiralOrderTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new SpiralOrder(); }

  void TearDown() override { delete exec; }

 protected:
  SpiralOrder* exec{nullptr};
};

TEST_F(SpiralOrderTest, spiralOrder) {
  std::vector<std::vector<int>> nums1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector<int> res1 = exec->spiralOrder(nums1);
  ASSERT_EQ(nums1.size() * nums1.at(0).size(), res1.size());
  ASSERT_EQ(1, res1[0]);
  ASSERT_EQ(6, res1[3]);
  ASSERT_EQ(7, res1[6]);
  ASSERT_EQ(5, res1[8]);

  std::vector<std::vector<int>> nums2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  std::vector<int> res2 = exec->spiralOrder(nums2);
  ASSERT_EQ(nums2.size() * nums2.at(0).size(), res2.size());
  ASSERT_EQ(1, res2[0]);
  ASSERT_EQ(8, res2[4]);
  ASSERT_EQ(9, res2[8]);
  ASSERT_EQ(7, res2[11]);

  std::vector<std::vector<int>> nums3 = {{2, 5}, {8, 4}, {0, -1}};
  std::vector<int> res3 = exec->spiralOrder(nums3);
  ASSERT_EQ(nums3.size() * nums3.at(0).size(), res3.size());
  ASSERT_EQ(2, res3[0]);
  ASSERT_EQ(-1, res3[3]);
  ASSERT_EQ(8, res3[5]);
}
}  // namespace array
}  // namespace algo