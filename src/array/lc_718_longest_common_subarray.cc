#include "array/lc_718_longest_common_subarray.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class FindLengthTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new FindLength(); }

  void TearDown() override { delete exec; }

 protected:
  FindLength* exec{nullptr};
};

TEST_F(FindLengthTest, solve1) {
  std::vector<int> nums11 = {1, 2, 3, 2, 1};
  std::vector<int> nums12 = {3, 2, 1, 4, 7};
  ASSERT_EQ(3, exec->solve1(nums11, nums12));

  std::vector<int> nums21 = {0, 0, 0, 0, 0};
  std::vector<int> nums22 = {0, 0, 0, 0, 0};
  ASSERT_EQ(5, exec->solve1(nums21, nums22));

  std::vector<int> nums31 = {1, 2, 3, 2, 8};
  std::vector<int> nums32 = {5, 6, 1, 4, 7};
  ASSERT_EQ(1, exec->solve1(nums31, nums32));
};

TEST_F(FindLengthTest, solve2) {
  std::vector<int> nums11 = {1, 2, 3, 2, 1};
  std::vector<int> nums12 = {3, 2, 1, 4, 7};
  ASSERT_EQ(3, exec->solve2(nums11, nums12));

  std::vector<int> nums21 = {0, 0, 0, 0, 0};
  std::vector<int> nums22 = {0, 0, 0, 0, 0};
  ASSERT_EQ(5, exec->solve2(nums21, nums22));

  std::vector<int> nums31 = {1, 2, 3, 2, 8};
  std::vector<int> nums32 = {5, 6, 1, 4, 7};
  ASSERT_EQ(1, exec->solve2(nums31, nums32));
};
};  // namespace array
}  // namespace algo