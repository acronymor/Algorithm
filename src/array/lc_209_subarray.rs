use std::cmp::min;
use std::usize;

///
/// # 长度最小的子数组
///
/// ## 描述
/// 给定一个含有 n 个正整数的数组和一个正整数 target 。
/// 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
/// 并返回其长度。如果不存在符合条件的子数组，返回 0 。
///
/// ## 示例
/// 输入：target = 7, nums = [2,3,1,2,4,3]
/// 输出：2
/// 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
///
/// 输入：target = 4, nums = [1,4,4]
/// 输出：1
///
/// 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
/// 输出：0
///
/// ## 链接
/// [leetcode-209](https://leetcode.cn/problems/minimum-size-subarray-sum/description/)
///

fn min_sub_array_len1(target: i32, nums: Vec<i32>) -> i32 {
    let mut len = i32::MAX;
    for j in 0..nums.len() {
        let mut i = j as i32;
        let mut sum = 0;
        while sum < target && i >= 0 {
            sum += nums[i as usize];
            i -= 1;
        }
        if sum >= target {
            len = min(len, j as i32 - i);
        }
    }
    return if len == i32::MAX { 0 } else { len };
}

fn min_sub_array_len2(target: i32, nums: Vec<i32>) -> i32 {
    let mut len = usize::MAX;
    let mut sum = 0;
    let mut i = 0;
    for j in 0..nums.len() {
        sum += nums[j];

        while sum >= target {
            len = min(len, j - i + 1);
            sum -= nums[i];
            i += 1;
        }
    }
    return if len == usize::MAX { 0 } else { len as i32 };
}


#[cfg(test)]
mod tests {
    use crate::array::lc_209_subarray::min_sub_array_len1;
    use crate::array::lc_209_subarray::min_sub_array_len2;

    #[test]
    fn test_min_sub_array_len1() {
        let nums: Vec<i32> = vec![2, 3, 1, 2, 4, 3];
        let res = min_sub_array_len1(7, nums);
        assert_eq!(2, res);

        let nums: Vec<i32> = vec![1, 4, 4];
        let res = min_sub_array_len1(4, nums);
        assert_eq!(1, res);

        let nums: Vec<i32> = vec![1, 1, 1, 1, 1, 1, 1, 1];
        let res = min_sub_array_len1(11, nums);
        assert_eq!(0, res);

        let nums: Vec<i32> = vec![1, 2, 3, 4, 5];
        let res = min_sub_array_len1(11, nums);
        assert_eq!(3, res);
    }

    #[test]
    fn test_min_sub_array_len2() {
        let nums: Vec<i32> = vec![2, 3, 1, 2, 4, 3];
        let res = min_sub_array_len2(7, nums);
        assert_eq!(2, res);

        let nums: Vec<i32> = vec![1, 4, 4];
        let res = min_sub_array_len2(4, nums);
        assert_eq!(1, res);

        let nums: Vec<i32> = vec![1, 1, 1, 1, 1, 1, 1, 1];
        let res = min_sub_array_len2(11, nums);
        assert_eq!(0, res);

        let nums: Vec<i32> = vec![1, 2, 3, 4, 5];
        let res = min_sub_array_len2(11, nums);
        assert_eq!(3, res);
    }
}