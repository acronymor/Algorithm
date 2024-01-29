///
/// # 移动零
///
/// ## 描述
/// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
/// 请注意 ，必须在不复制数组的情况下原地对数组进行操作。
///
/// ## 示例
/// 输入: nums = [0,1,0,3,12]
/// 输出: [1,3,12,0,0]
///
/// 输入: nums = [0]
/// 输出: [0]
///
/// ## 链接
/// [leetcode-283](https://leetcode.cn/problems/move-zeroes/)
///

fn move_zeroes(nums: &mut Vec<i32>) {
    let mut i: usize = 0;
    for j in 0..nums.len() {
        if nums[j] != 0 {
            nums.swap(i, j);
            i += 1;
        }
    }
}


#[cfg(test)]
mod tests {
    use crate::array::lc_283_move_zeroes::move_zeroes;

    #[test]
    fn test_move_zeroes() {
        let mut nums: Vec<i32> = vec![0, 1, 0, 3, 12];
        move_zeroes(&mut nums);
        assert_eq!(vec![1, 3, 12, 0, 0], nums);


        let mut nums: Vec<i32> = vec![1, 1];
        move_zeroes(&mut nums);
        assert_eq!(vec![1, 1], nums);
    }
}