#include "math/lc_912_sort_an_array.h"

#include "gtest/gtest.h"

namespace algo {
namespace math {
class SortArrayTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new SortArray(); }

  void TearDown() override { delete exec; }

 protected:
  SortArray* exec{nullptr};
};

TEST_F(SortArrayTest, bubbleSort) {
  std::vector<int> nums1 = {5, 2, 3, 1};
  std::vector<int> res1 = exec->bubbleSort(nums1);
  ASSERT_EQ(1, res1.at(0));
  ASSERT_EQ(2, res1.at(1));
  ASSERT_EQ(3, res1.at(2));
  ASSERT_EQ(5, res1.at(3));

  std::vector<int> nums2 = {5, 2, 3, 1, 0, 0};
  std::vector<int> res2 = exec->bubbleSort(nums2);
  ASSERT_EQ(0, res2.at(0));
  ASSERT_EQ(0, res2.at(1));

  std::vector<int> nums3 = {1};
  std::vector<int> res3 = exec->bubbleSort(nums3);
  ASSERT_EQ(1, res3.at(0));

  std::vector<int> nums4 = {};
  std::vector<int> res4 = exec->bubbleSort(nums4);
  ASSERT_EQ(0, res4.size());
}

TEST_F(SortArrayTest, quickSort) {
  std::vector<int> nums1 = {5, 2, 3, 1};
  std::vector<int> res1 = exec->quickSort(nums1);
  ASSERT_EQ(1, res1.at(0));
  ASSERT_EQ(2, res1.at(1));
  ASSERT_EQ(3, res1.at(2));
  ASSERT_EQ(5, res1.at(3));

  std::vector<int> nums2 = {5, 2, 3, 1, 0, 0};
  std::vector<int> res2 = exec->quickSort(nums2);
  ASSERT_EQ(0, res2.at(0));
  ASSERT_EQ(0, res2.at(1));

  std::vector<int> nums3 = {1};
  std::vector<int> res3 = exec->quickSort(nums3);
  ASSERT_EQ(1, res3.at(0));

  std::vector<int> nums4 = {};
  std::vector<int> res4 = exec->quickSort(nums4);
  ASSERT_EQ(0, res4.size());
}

TEST_F(SortArrayTest, selectSort) {
  std::vector<int> nums1 = {5, 2, 3, 1};
  std::vector<int> res1 = exec->selectSort(nums1);
  ASSERT_EQ(1, res1.at(0));
  ASSERT_EQ(2, res1.at(1));
  ASSERT_EQ(3, res1.at(2));
  ASSERT_EQ(5, res1.at(3));

  std::vector<int> nums2 = {5, 2, 3, 1, 0, 0};
  std::vector<int> res2 = exec->selectSort(nums2);
  ASSERT_EQ(0, res2.at(0));
  ASSERT_EQ(0, res2.at(1));

  std::vector<int> nums3 = {1};
  std::vector<int> res3 = exec->selectSort(nums3);
  ASSERT_EQ(1, res3.at(0));

  std::vector<int> nums4 = {};
  std::vector<int> res4 = exec->selectSort(nums4);
  ASSERT_EQ(0, res4.size());
}

TEST_F(SortArrayTest, heapSort) {
  std::vector<int> nums1 = {5, 2, 3, 1};
  std::vector<int> res1 = exec->heapSort(nums1);
  ASSERT_EQ(1, res1.at(0));
  ASSERT_EQ(2, res1.at(1));
  ASSERT_EQ(3, res1.at(2));
  ASSERT_EQ(5, res1.at(3));

  std::vector<int> nums2 = {5, 2, 3, 1, 0, 0};
  std::vector<int> res2 = exec->heapSort(nums2);
  ASSERT_EQ(0, res2.at(0));
  ASSERT_EQ(0, res2.at(1));

  std::vector<int> nums3 = {1};
  std::vector<int> res3 = exec->heapSort(nums3);
  ASSERT_EQ(1, res3.at(0));

  std::vector<int> nums4 = {};
  std::vector<int> res4 = exec->heapSort(nums4);
  ASSERT_EQ(0, res4.size());
}

TEST_F(SortArrayTest, insertSort) {
  std::vector<int> nums1 = {5, 2, 3, 1};
  std::vector<int> res1 = exec->insertSort(nums1);
  ASSERT_EQ(1, res1.at(0));
  ASSERT_EQ(2, res1.at(1));
  ASSERT_EQ(3, res1.at(2));
  ASSERT_EQ(5, res1.at(3));

  std::vector<int> nums2 = {5, 2, 3, 1, 0, 0};
  std::vector<int> res2 = exec->insertSort(nums2);
  ASSERT_EQ(0, res2.at(0));
  ASSERT_EQ(0, res2.at(1));

  std::vector<int> nums3 = {1};
  std::vector<int> res3 = exec->insertSort(nums3);
  ASSERT_EQ(1, res3.at(0));

  std::vector<int> nums4 = {};
  std::vector<int> res4 = exec->insertSort(nums4);
  ASSERT_EQ(0, res4.size());
}
}  // namespace math
}  // namespace algo
