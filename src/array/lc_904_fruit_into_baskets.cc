#include "array/lc_904_fruit_into_baskets.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class TotalFruitTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new TotalFruit(); }

  void TearDown() override { delete exec; }

 protected:
  TotalFruit* exec{nullptr};
};

TEST_F(TotalFruitTest, totalFruit) {
  std::vector<int> nums1 = {1, 2, 1};
  ASSERT_EQ(3, exec->totalFruit(nums1));

  std::vector<int> nums2 = {0, 1, 2, 1};
  ASSERT_EQ(3, exec->totalFruit(nums2));

  std::vector<int> nums3 = {1, 2, 3, 2, 2};
  ASSERT_EQ(4, exec->totalFruit(nums3));

  std::vector<int> nums4 = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
  ASSERT_EQ(5, exec->totalFruit(nums4));
}
}  // namespace array
}  // namespace algo