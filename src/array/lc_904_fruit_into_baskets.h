#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdint>

/**
 * @namespace array
 * @brief 水果成篮
 */

namespace algo {
namespace array {

/**
 * @brief 水果成篮
 *
 * @details
 * 你正在探访一家农场，农场从左到右种植了一排果树。这些树用一个整数数组 fruits 表示，其中 fruits[i] 是第 i 棵树上的水果
 * 种类 。 你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规矩，你必须按照要求采摘水果：
 * - 你只有两个篮子，并且每个篮子只能装单一类型的水果。每个篮子能够装的水果总量没有限制。
 * - 你可以选择任意一棵树开始采摘，你必须从每棵树（包括开始采摘的树）上恰好摘一个水果。
 * 采摘的水果应当符合篮子中的水果类型。每采摘一次，你将会向右移动到下一棵树，并继续采摘。
 * - 一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘。
 * 给你一个整数数组 fruits ，返回你可以收集的水果的 最大 数目。
 *
 * @par 示例
 *
 * 输入：fruits = [1,2,1]
 * 输出：3
 * 解释：可以采摘全部 3 棵树。
 *
 * 输入：fruits = [0,1,2,2]
 * 输出：3
 * 解释：可以采摘 [1,2,2] 这三棵树。
 * 如果从第一棵树开始采摘，则只能采摘 [0,1] 这两棵树。
 *
 * @see [leetcode-904](https://leetcode.cn/problems/fruit-into-baskets)
 */

class TotalFruit {
 public:
  /**
   * @ingroup sliding-window
   */
  int totalFruit(std::vector<int>& fruits) {
    std::unordered_map<int, uint32_t> map;
    int res = 0;
    for (int i = 0, j = 0; j < fruits.size(); j++) {
      map[fruits[j]]++;
      while (map.size() > 2) {
        auto it = map.find(fruits[i]);
        it->second--;
        if (it->second == 0) {
          map.erase(it);
        }
        i++;
      }
      res = std::max(res, j - i + 1);
    }
    return res;
  }
};
}  // namespace array
}  // namespace algo