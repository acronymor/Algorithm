#include "lc_239_sliding_window_maximum.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class MaxSlidingWindowTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MaxSlidingWindow(); }

  void TearDown() override { delete exec; }

 protected:
  MaxSlidingWindow* exec{nullptr};
};

TEST_F(MaxSlidingWindowTest, maxSlidingWindow1) {
  std::vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
  int k1 = 3;
  std::vector<int> res1 = exec->maxSlidingWindow1(nums1, k1);
  ASSERT_EQ(3, res1.at(0));
  ASSERT_EQ(5, res1.at(2));
  ASSERT_EQ(7, res1.at(5));

  std::vector<int> nums2 = {1};
  int k2 = 1;
  std::vector<int> res2 = exec->maxSlidingWindow1(nums2, k2);
  ASSERT_EQ(1, res2.at(0));

  std::vector<int> nums3 = {1, -1};
  int k3 = 1;
  std::vector<int> res3 = exec->maxSlidingWindow1(nums3, k3);
  ASSERT_EQ(1, res3.at(0));
  ASSERT_EQ(-1, res3.at(1));
};

TEST_F(MaxSlidingWindowTest, maxSlidingWindow2) {
  std::vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
  int k1 = 3;
  std::vector<int> res1 = exec->maxSlidingWindow2(nums1, k1);
  ASSERT_EQ(3, res1.at(0));
  ASSERT_EQ(5, res1.at(2));
  ASSERT_EQ(7, res1.at(5));

  std::vector<int> nums2 = {1};
  int k2 = 1;
  std::vector<int> res2 = exec->maxSlidingWindow2(nums2, k2);
  ASSERT_EQ(1, res2.at(0));

  std::vector<int> nums3 = {1, -1};
  int k3 = 1;
  std::vector<int> res3 = exec->maxSlidingWindow2(nums3, k3);
  ASSERT_EQ(1, res3.at(0));
  ASSERT_EQ(-1, res3.at(1));
};

TEST_F(MaxSlidingWindowTest, maxSlidingWindow3) {
  std::vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
  int k1 = 3;
  std::vector<int> res1 = exec->maxSlidingWindow3(nums1, k1);
  ASSERT_EQ(3, res1.at(0));
  ASSERT_EQ(5, res1.at(2));
  ASSERT_EQ(7, res1.at(5));

  std::vector<int> nums2 = {1};
  int k2 = 1;
  std::vector<int> res2 = exec->maxSlidingWindow3(nums2, k2);
  ASSERT_EQ(1, res2.at(0));

  std::vector<int> nums3 = {1, -1};
  int k3 = 1;
  std::vector<int> res3 = exec->maxSlidingWindow3(nums3, k3);
  ASSERT_EQ(1, res3.at(0));
  ASSERT_EQ(-1, res3.at(1));
};
}  // namespace array
};  // namespace algo
