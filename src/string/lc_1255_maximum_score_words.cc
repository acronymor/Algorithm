#include "string/lc_1255_maximum_score_words.h"

#include "gtest/gtest.h"

namespace algo {
namespace string {
class MaxScoreWordsTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new MaxScoreWords(); }

  void TearDown() override { delete exec; }

 protected:
  MaxScoreWords* exec{nullptr};
};

TEST_F(MaxScoreWordsTest, minDistance) {
  std::vector<std::string> words1 = {"dog", "cat", "dad", "good"};
  std::vector<char> letters1 = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
  std::vector<int> score1 = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int res1 = exec->solve(words1, letters1, score1);
  ASSERT_EQ(23, res1);

  std::vector<std::string> words2 = {"xxxz", "ax", "bx", "cx"};
  std::vector<char> letters2 = {'z', 'a', 'b', 'c', 'x', 'x', 'x'};
  std::vector<int> score2 = {4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10};
  int res2 = exec->solve(words2, letters2, score2);
  ASSERT_EQ(27, res2);

  std::vector<std::string> words3 = {"leetcode"};
  std::vector<char> letters3 = {'l', 'e', 't', 'c', 'o', 'd'};
  std::vector<int> score3 = {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
  int res3 = exec->solve(words3, letters3, score3);
  ASSERT_EQ(0, res3);
}
}  // namespace string
}  // namespace algo
