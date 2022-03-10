#include "array/lc_42_trapping_water.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class TrapWaterTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new TrapWater(); }

  void TearDown() override { delete exec; }

 protected:
  TrapWater* exec{nullptr};
};

TEST_F(TrapWaterTest, trap1) {
  std::vector<int> nums1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  ASSERT_EQ(6, exec->trap1(nums1));

  std::vector<int> nums2 = {4, 2, 0, 3, 2, 5};
  ASSERT_EQ(9, exec->trap1(nums2));

  std::vector<int> nums3 = {2, 0, 2};
  ASSERT_EQ(2, exec->trap1(nums3));
}

TEST_F(TrapWaterTest, trap2) {
  std::vector<int> nums1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  ASSERT_EQ(6, exec->trap2(nums1));

  std::vector<int> nums2 = {4, 2, 0, 3, 2, 5};
  ASSERT_EQ(9, exec->trap2(nums2));

  std::vector<int> nums3 = {2, 0, 2};
  ASSERT_EQ(2, exec->trap2(nums3));
}

TEST_F(TrapWaterTest, trap3) {
  std::vector<int> nums1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  ASSERT_EQ(6, exec->trap3(nums1));

  std::vector<int> nums2 = {4, 2, 0, 3, 2, 5};
  ASSERT_EQ(9, exec->trap3(nums2));

  std::vector<int> nums3 = {2, 0, 2};
  ASSERT_EQ(2, exec->trap3(nums3));
}

TEST_F(TrapWaterTest, trap4) {
  std::vector<int> nums1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  ASSERT_EQ(6, exec->trap4(nums1));

  std::vector<int> nums2 = {4, 2, 0, 3, 2, 5};
  ASSERT_EQ(9, exec->trap4(nums2));

  std::vector<int> nums3 = {2, 0, 2};
  ASSERT_EQ(2, exec->trap4(nums3));
}
}  // namespace array
}  // namespace algo
