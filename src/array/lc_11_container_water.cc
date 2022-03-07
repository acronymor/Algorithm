#include "array/lc_11_container_water.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class MaxAreaTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MaxArea(); }

  void TearDown() override { delete exec; }

 protected:
  MaxArea* exec{nullptr};
};

TEST_F(MaxAreaTest, maxArea) {
  std::vector<int> nums1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  ASSERT_EQ(49, exec->maxArea(nums1));

  std::vector<int> nums2 = {1, 1};
  ASSERT_EQ(1, exec->maxArea(nums2));
}
}  // namespace array
}  // namespace algo
