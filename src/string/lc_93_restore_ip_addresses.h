#include <iostream>
#include <string>
#include <vector>

/**
 * @namespace string
 * @brief 复原 IP 地址
 */

namespace algo {
namespace string {

/**
 * @brief 复原 IP 地址
 *
 * @details
 * 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
 * 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP
 * 地址。 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入
 * '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
 *
 * @par 示例
 *
 * 输入：s = "25525511135"
 * 输出：["255.255.11.135","255.255.111.35"]
 *
 * 输入：s = "0000"
 * 输出：["0.0.0.0"]
 *
 * @see [leetcode-93](https://leetcode.cn/problems/restore-ip-addresses/)
 */

class RestoreIpAddresses {
 public:
  std::vector<std::string> restoreIpAddresses(std::string s) {
    std::vector<std::string> res;
    std::string build;
    backtracking(s, res, build, 0, 0);
    for (auto& ip : res) {
      ip.pop_back();
    }
    return res;
  }

 private:
  void backtracking(const std::string& s, std::vector<std::string>& res, std::string& build, int start, int segment) {
    if (start == s.length() && segment == 4) {
      res.push_back(build);
      return;
    }

    if (start == s.length() || segment == 4) {
      return;
    }

    for (int i = start; i < s.length(); i++) {
      if (!isValid(s, start, i)) {
        break;
      }
      std::string str = s.substr(start, i - start + 1);
      build.append(str);
      build.append(".");
      backtracking(s, res, build, i + 1, segment + 1);
      build.pop_back();
      build.erase(build.end() - str.length(), build.end());
    }
  }

  bool isValid(const std::string& s, int start, int end) {
    if (end - start > 3) {
      return false;
    }

    if (s[start] == '0' && start != end) {
      return false;
    }

    int num = 0;
    for (int i = start; i <= end; i++) {
      num = num * 10 + (s[i] - '0');
    }

    return num <= 255;
  }
};
}  // namespace string
}  // namespace algo