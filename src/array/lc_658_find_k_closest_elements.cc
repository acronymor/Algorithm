#include "array/lc_658_find_k_closest_elements.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class FindClosestElementsTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new FindClosestElements(); }

  void TearDown() override { delete exec; }

 protected:
  FindClosestElements* exec{nullptr};
};

TEST_F(FindClosestElementsTest, solve1) {
  std::vector<int> arr1 = {1, 2, 3, 4, 5};
  int k1 = 4, x1 = 3;
  std::vector<int> res1 = exec->solve1(arr1, k1, x1);
  ASSERT_EQ(1, res1[0]);
  ASSERT_EQ(2, res1[1]);
  ASSERT_EQ(3, res1[2]);
  ASSERT_EQ(4, res1[3]);

  std::vector<int> arr2 = {1, 2, 3, 4, 5};
  int k2 = 4, x2 = -1;
  std::vector<int> res2 = exec->solve1(arr2, k2, x2);
  ASSERT_EQ(1, res2[0]);
  ASSERT_EQ(2, res2[1]);
  ASSERT_EQ(3, res2[2]);
  ASSERT_EQ(4, res2[3]);
}

TEST_F(FindClosestElementsTest, solve2) {
  std::vector<int> arr1 = {1, 2, 3, 4, 5};
  int k1 = 4, x1 = 3;
  std::vector<int> res1 = exec->solve2(arr1, k1, x1);
  ASSERT_EQ(1, res1[0]);
  ASSERT_EQ(2, res1[1]);
  ASSERT_EQ(3, res1[2]);
  ASSERT_EQ(4, res1[3]);

  std::vector<int> arr2 = {1, 2, 3, 4, 5};
  int k2 = 4, x2 = -1;
  std::vector<int> res2 = exec->solve2(arr2, k2, x2);
  ASSERT_EQ(1, res2[0]);
  ASSERT_EQ(2, res2[1]);
  ASSERT_EQ(3, res2[2]);
  ASSERT_EQ(4, res2[3]);
}

TEST_F(FindClosestElementsTest, solve3) {
  std::vector<int> arr1 = {1, 2, 3, 4, 5};
  int k1 = 4, x1 = 3;
  std::vector<int> res1 = exec->solve3(arr1, k1, x1);
  ASSERT_EQ(1, res1[0]);
  ASSERT_EQ(2, res1[1]);
  ASSERT_EQ(3, res1[2]);
  ASSERT_EQ(4, res1[3]);

  std::vector<int> arr2 = {1, 2, 3, 4, 5};
  int k2 = 4, x2 = -1;
  std::vector<int> res2 = exec->solve3(arr2, k2, x2);
  ASSERT_EQ(1, res2[0]);
  ASSERT_EQ(2, res2[1]);
  ASSERT_EQ(3, res2[2]);
  ASSERT_EQ(4, res2[3]);

  std::vector<int> arr3 = {-2, -1, 1, 2, 3, 4, 5};
  int k3 = 7, x3 = 3;
  std::vector<int> res3 = exec->solve3(arr3, k3, x3);
  ASSERT_EQ(-2, res3[0]);
  ASSERT_EQ(-1, res3[1]);
  ASSERT_EQ(1, res3[2]);
  ASSERT_EQ(2, res3[3]);
}
}  // namespace array
}  // namespace algo
