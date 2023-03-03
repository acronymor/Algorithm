#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/**
 * @namespace string
 * @brief 保证文件名唯一
 */

namespace algo {
namespace string {

/**
 * @brief 保证文件名唯一
 *
 * @details
 * 给你一个长度为 n 的字符串数组 names 。你将会在文件系统中创建 n 个文件夹：在第 i 分钟，新建名为 names[i] 的文件夹。
 * 由于两个文件 不能 共享相同的文件名，因此如果新建文件夹使用的文件名已经被占用，系统会以 (k)
 * 的形式为新文件夹的文件名添加后缀，其中 k 是能保证文件名唯一的 最小正整数 。 返回长度为 n 的字符串数组，其中 ans[i]
 * 是创建第 i 个文件夹时系统分配给该文件夹的实际名称。
 *
 * @par 示例
 *
 * 输入：names = ["pes","fifa","gta","pes(2019)"]
 * 输出：["pes","fifa","gta","pes(2019)"]
 *
 * @see [leetcode-1487](https://leetcode.cn/problems/making-file-names-unique/)
 */

class GetFolderNames {
 public:
  std::vector<std::string> solve1(std::vector<std::string>& names) {
    std::vector<std::string> res(names.size());
    std::unordered_map<std::string, int> map;
    for (int i = 0; i < names.size(); i++) {
      if (map.count(names[i]) == 0) {
        map[names[i]] = 1;
        res[i] = names[i];
      } else {
        int no = map[names[i]];
        std::string tmp = names[i] + "(" + std::to_string(no) + ")";
        while (map.count(tmp) > 0) {
          no++;
          tmp = names[i] + "(" + std::to_string(no) + ")";
        }
        res[i] = tmp;
        map[tmp] = 1;
        map[names[i]]++;
      }
    }
    return res;
  }

  std::vector<std::string> solve2(std::vector<std::string>& names) {
    std::unordered_map<std::string, int> map;
    for (int i = 0; i < names.size(); i++) {
      std::string ori_name = names[i];
      while (map.find(names[i]) != map.end()) {
        names[i] = ori_name + "(" + std::to_string(map[ori_name]) + ")";
        map[ori_name]++;
      }
      map[names[i]]++;
    }
    return names;
  }
};
}  // namespace string
}  // namespace algo