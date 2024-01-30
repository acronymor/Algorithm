///
/// # 有序数组的平方
///
/// ## 描述
/// 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
///
/// ## 示例
/// 输入：nums = [-4,-1,0,3,10]
/// 输出：[0,1,9,16,100]
/// 解释：平方后，数组变为 [16,1,0,9,100]
/// 排序后，数组变为 [0,1,9,16,100]
///
/// 输入：nums = [-7,-3,2,3,11]
/// 输出：[4,9,9,49,121]
///
/// ## 链接
/// [leetcode-977](https://leetcode.cn/problems/squares-of-a-sorted-array/)
///

fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
    let mut res: Vec<i32> = vec![0; nums.len()];

    let mut i: usize = 0;
    let mut j: usize = nums.len() - 1;
    let mut k: isize = j as isize;

    while i <= j {
        let left = nums[i] * nums[i];
        let right = nums[j] * nums[j];
        if left < right {
            res[k as usize] = right;
            j -= 1;
        } else {
            res[k as usize] = left;
            i += 1;
        }
        k -= 1;
    }

    return res;
}

#[cfg(test)]
mod tests {
    use crate::array::lc_977_sorted_squares::sorted_squares;

    #[test]
    fn test_sorted_squares() {
        let nums: Vec<i32> = Vec::from([-4, -1, 0, 3, 10]);
        let res: Vec<i32> = sorted_squares(nums);
        assert_eq!(vec![0, 1, 9, 16, 100], res);

        let nums: Vec<i32> = Vec::from([-7, -3, 2, 3, 11]);
        let res: Vec<i32> = sorted_squares(nums);
        assert_eq!(vec![4, 9, 9, 49, 121], res);
    }
}