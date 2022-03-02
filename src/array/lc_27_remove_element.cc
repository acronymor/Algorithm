#include "array/lc_27_remove_element.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class RemoveElementTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new RemoveElement(); }

  void TearDown() override { delete exec; }

 protected:
  RemoveElement* exec{nullptr};
};

TEST_F(RemoveElementTest, RemoveElement) {
  std::vector<int> nums1 = {3, 2, 2, 3};
  int target1 = 3;
  ASSERT_EQ(2, exec->removeElement(nums1, target1));

  std::vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
  int target2 = 2;
  ASSERT_EQ(5, exec->removeElement(nums2, target2));
}
}  // namespace array
};  // namespace algo