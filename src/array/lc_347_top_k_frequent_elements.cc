#include "array/lc_347_top_k_frequent_elements.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class TopKFrequentTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new TopKFrequent(); }

  void TearDown() override { delete exec; }

 protected:
  TopKFrequent* exec{nullptr};
};

TEST_F(TopKFrequentTest, maxArea) {
  std::vector<int> nums1 = {1, 1, 1, 2, 2, 3};
  int k1 = 2;
  std::vector<int> res1 = exec->topKFrequent(nums1, k1);
  ASSERT_EQ(1, res1[0]);
  ASSERT_EQ(2, res1[1]);

  std::vector<int> nums2 = {1};
  int k2 = 1;
  std::vector<int> res2 = exec->topKFrequent(nums2, k2);
  ASSERT_EQ(1, res2[0]);
}
}  // namespace array
}  // namespace algo
