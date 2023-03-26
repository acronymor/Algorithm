#include "lc_405_convert_number.h"

#include "gtest/gtest.h"

namespace algo {
namespace math {
class ConvertNumberTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new ConvertNumber(); }

  void TearDown() override { delete exec; }

 protected:
  ConvertNumber* exec{nullptr};
};

TEST_F(ConvertNumberTest, combine) {
  std::string res1 = exec->toHex(26);
  ASSERT_EQ("1a", res1);

  std::string res2 = exec->toHex(-1);
  ASSERT_EQ("ffffffff", res2);
}

}  // namespace math
}  // namespace algo
