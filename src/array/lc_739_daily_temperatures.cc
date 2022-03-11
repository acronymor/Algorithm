#include "array/lc_739_daily_temperatures.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class DailyTemperaturesTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new DailyTemperatures(); }

  void TearDown() override { delete exec; }

 protected:
  DailyTemperatures* exec{nullptr};
};

TEST_F(DailyTemperaturesTest, dailyTemperatures) {
  std::vector<int> nums1 = {73, 74, 75, 71, 69, 72, 76, 73};
  std::vector<int> res1 = exec->dailyTemperatures(nums1);
  ASSERT_EQ(1, res1[0]);
  ASSERT_EQ(4, res1[2]);
  ASSERT_EQ(1, res1[4]);

  std::vector<int> nums2 = {30, 40, 50, 60};
  std::vector<int> res2 = exec->dailyTemperatures(nums2);
  ASSERT_EQ(1, res2[0]);
  ASSERT_EQ(1, res2[1]);
  ASSERT_EQ(0, res2[3]);
}
}  // namespace array
}  // namespace algo