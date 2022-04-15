#include "string/lc_1047_remove_duplicates.h"

#include "gtest/gtest.h"

namespace algo {
namespace string {
class RemoveDuplicatesTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new RemoveDuplicates(); }

  void TearDown() override { delete exec; }

 protected:
  RemoveDuplicates* exec{nullptr};
};

TEST_F(RemoveDuplicatesTest, removeDuplicates) {
  std::string s1 = "abbaca";
  std::string res1 = exec->removeDuplicates(s1);
  ASSERT_EQ("ca", res1);

  std::string s2 = "abbbaca";
  std::string res2 = exec->removeDuplicates(s2);
  ASSERT_EQ("abaca", res2);
}
}  // namespace string
}  // namespace algo
