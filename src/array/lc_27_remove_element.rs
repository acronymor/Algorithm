///
/// # 移除元素
///
/// ## 描述
/// 给你一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，并返回移除后数组的新长度。
/// 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。
/// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
///
/// ## 示例
/// 输入: nums = [3,2,2,3], val = 3
/// 输出: 2, nums = [2,2]
///
/// >> 解释: 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
/// >> 你不需要考虑数组中超出新长度后面的元素。例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或
/// >> nums = [2,2,0,0]，也会被视作正确答案。
///
/// 输入：nums = [0,1,2,2,3,0,4,2], val = 2
/// 输出：5, nums = [0,1,4,0,3]
///
/// >> 解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
/// >> 注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。
///
/// ## 链接
/// [leetcode-27](https://leetcode.cn/problems/remove-element/)
///
///
pub fn remove_element1(nums: &mut Vec<i32>, val: i32) -> i32 {
    let mut i = 0;
    for j in 0..nums.len() {
        if nums[j] != val {
            nums[i] = nums[j];
            i += 1;
        }
    }
    return i as i32;
}

pub fn remove_element2(nums: &mut Vec<i32>, val: i32) -> i32 {
    nums.retain(|&x| x != val);
    nums.len() as i32
}


#[cfg(test)]
mod tests {
    use crate::array::lc_27_remove_element::{remove_element1, remove_element2};

    #[test]
    fn test_remove_element1() {
        let mut nums: Vec<i32> = vec![3, 2, 2, 3];
        let target: i32 = 3;
        let res: i32 = remove_element1(&mut nums, target);
        assert_eq!(2, res);

        let mut nums: Vec<i32> = vec![0, 1, 2, 2, 3, 0, 4, 2];
        let target: i32 = 2;
        let res: i32 = remove_element1(&mut nums, target);
        assert_eq!(5, res);
    }

    #[test]
    fn test_remove_element2() {
        let mut nums: Vec<i32> = vec![3, 2, 2, 3];
        let target: i32 = 3;
        let res: i32 = remove_element2(&mut nums, target);
        assert_eq!(2, res);

        let mut nums: Vec<i32> = vec![0, 1, 2, 2, 3, 0, 4, 2];
        let target: i32 = 2;
        let res: i32 = remove_element2(&mut nums, target);
        assert_eq!(5, res);
    }
}