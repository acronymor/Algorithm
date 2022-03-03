#include "array/lc_26_remove_dup_element.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class RemoveDupElementTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new RemoveDupElement(); }

  void TearDown() override { delete exec; }

 protected:
  RemoveDupElement* exec{nullptr};
};

TEST_F(RemoveDupElementTest, removeDuplicates) {
  std::vector<int> nums1 = {1, 1, 2};
  ASSERT_EQ(2, exec->removeDuplicates(nums1));

  std::vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  ASSERT_EQ(5, exec->removeDuplicates(nums2));

  std::vector<int> nums3 = {1, 1};
  ASSERT_EQ(1, exec->removeDuplicates(nums3));
}
}  // namespace array
}  // namespace algo
