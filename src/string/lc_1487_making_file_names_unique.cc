#include "string/lc_1487_making_file_names_unique.h"

#include "gtest/gtest.h"

namespace algo {
namespace string {
class GetFolderNamesTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new GetFolderNames(); }

  void TearDown() override { delete exec; }

 protected:
  GetFolderNames* exec{nullptr};
};

TEST_F(GetFolderNamesTest, solve1) {
  std::vector<std::string> names1 = {"pes", "fifa", "gta", "pes(2019)"};
  std::vector<std::string> res1 = exec->solve1(names1);
  ASSERT_EQ("gta", res1[2]);

  std::vector<std::string> names2 = {"gta", "gta(1)", "gta", "avalon"};
  std::vector<std::string> res2 = exec->solve1(names2);
  ASSERT_EQ("gta(2)", res2[2]);
}
}  // namespace string
}  // namespace algo
