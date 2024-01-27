///
/// # 搜索插入位置
///
/// ## 描述
/// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
/// 请必须使用时间复杂度为 O(log n) 的算法。
///
/// ## 示例
/// 输入: nums = [1,3,5,6], target = 5
/// 输出: 2
///
/// 输入: nums = [1,3,5,6], target = 2
/// 输出: 1
///
/// 输入: nums = [1,3,5,6], target = 7
/// 输出: 4
///
/// ## 链接
/// [leetcode-35](https://leetcode.cn/problems/search-insert-position/)
///

pub fn search_insert1(nums: Vec<i32>, target: i32) -> i32 {
    for i in 0..nums.len() {
        if nums[i] >= target {
            return i as i32;
        }
    }
    return nums.len() as i32;
}

pub fn search_insert2(nums: Vec<i32>, target: i32) -> i32 {
    let mut left = 0;
    let mut right = nums.len();

    while left < right {
        let mid = (left + right) / 2;
        if nums[mid] < target {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return right as i32;
}

#[cfg(test)]
mod tests {
    use crate::array::lc_35_search_insert_position::{search_insert1, search_insert2};

    #[test]
    fn test_search_insert1() {
        let nums: Vec<i32> = vec![1, 3, 5, 6];
        let target: i32 = 5;
        let res: i32 = search_insert1(nums, target);
        assert_eq!(2, res);

        let nums: Vec<i32> = vec![1, 3, 5, 6];
        let target: i32 = 2;
        let res: i32 = search_insert1(nums, target);
        assert_eq!(1, res);

        let nums: Vec<i32> = vec![1, 3, 5, 6];
        let target: i32 = 7;
        let res: i32 = search_insert1(nums, target);
        assert_eq!(4, res);
    }

    #[test]
    fn test_search_insert2() {
        let nums: Vec<i32> = vec![1, 3, 5, 6];
        let target: i32 = 5;
        let res: i32 = search_insert2(nums, target);
        assert_eq!(2, res);

        let nums: Vec<i32> = vec![1, 3, 5, 6];
        let target: i32 = 2;
        let res: i32 = search_insert2(nums, target);
        assert_eq!(1, res);

        let nums: Vec<i32> = vec![1, 3, 5, 6];
        let target: i32 = 7;
        let res: i32 = search_insert2(nums, target);
        assert_eq!(4, res);
    }
}