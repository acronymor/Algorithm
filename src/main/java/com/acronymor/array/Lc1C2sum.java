package com.acronymor.array;

import java.util.HashMap;

/**
 * <li> 两数之和 </li>
 * <p>
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个
 * 整数，并返回它们的数组下标。 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 你可以按任意顺序返回答案。
 *
 * <li> 示例 </li>
 * <pre>
 * 输入：nums = [2,7,11,15], target = 9
 * 输出：[0,1]
 * 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
 * </pre>
 * <pre>
 * 输入：nums = [3,2,4], target = 6
 * 输出：[1,2]
 * </pre>
 *
 * @see <a href="https://leetcode.cn/problems/two-sum/">leetcode-1</a>
 */

public class Lc1C2sum {
    public int[] solve(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>(nums.length);

        int[] res = new int[]{-1, -1};

        for (int i = 0; i < nums.length; i++) {
            int tmp = target - nums[i];
            if (map.containsKey(tmp)) {
                return new int[]{map.get(tmp), i};
            }

            map.put(nums[i], i);
        }

        return res;
    }
}
