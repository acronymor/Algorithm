#include "array/lc_435_non_overlapping_intervals.h"

#include "gtest/gtest.h"

namespace algo {
namespace array {
class EraseOverlapIntervalsTest : public ::testing::Test {
 protected:
  void SetUp() override { exec = new EraseOverlapIntervals(); }

  void TearDown() override { delete exec; }

 protected:
  EraseOverlapIntervals* exec{nullptr};
};

TEST_F(EraseOverlapIntervalsTest, solve1) {
  std::vector<std::vector<int>> intervals1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  ASSERT_EQ(1, exec->solve(intervals1));

  std::vector<std::vector<int>> intervals2 = {{1, 2}, {1, 2}, {1, 2}};
  ASSERT_EQ(2, exec->solve(intervals2));

  std::vector<std::vector<int>> intervals3 = {{1, 2}, {2, 3}};
  ASSERT_EQ(0, exec->solve(intervals3));
};
}  // namespace array
}  // namespace algo
