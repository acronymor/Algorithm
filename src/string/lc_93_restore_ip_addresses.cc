#include "string/lc_93_restore_ip_addresses.h"

#include "gtest/gtest.h"

namespace algo {
namespace string {
class RestoreIpAddressesTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new RestoreIpAddresses(); }

  void TearDown() override { delete exec; }

 protected:
  RestoreIpAddresses* exec{nullptr};
};

TEST_F(RestoreIpAddressesTest, partition) {
  std::string s1 = "25525511135";
  std::vector<std::string> res1 = exec->restoreIpAddresses(s1);
  ASSERT_EQ("255.255.11.135", res1[0]);
  ASSERT_EQ("255.255.111.35", res1[1]);

  std::string s2 = "0000";
  std::vector<std::string> res2 = exec->restoreIpAddresses(s2);
  ASSERT_EQ("0.0.0.0", res2[0]);

  std::string s3 = "101023";
  std::vector<std::string> res3 = exec->restoreIpAddresses(s3);
  ASSERT_EQ("1.0.10.23", res3[0]);
  ASSERT_EQ("1.0.102.3", res3[1]);
  ASSERT_EQ("10.1.0.23", res3[2]);
  ASSERT_EQ("10.10.2.3", res3[3]);
  ASSERT_EQ("101.0.2.3", res3[4]);
}
}  // namespace string
}  // namespace algo