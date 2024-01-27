///
/// # 二分查找
///
/// ## 描述
/// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的
/// target，如果目标值存在返回下标，否则返回 -1。
///
/// ## 示例
/// 输入: nums = [-1,0,3,5,9,12], target = 9
/// 输出: 4
/// 解释: 9 出现在 nums 中并且下标为 4
///
/// 输入: nums = [-1,0,3,5,9,12], target = 2
/// 输出: -1
/// 解释: 2 不存在 nums 中因此返回 -1
///
/// ## 链接
/// [leetcode-704](https://leetcode.cn/problems/binary-search/)
///

fn search1(nums: Vec<i32>, target: i32) -> i32 {
    let mut left: usize = 0;
    let mut right: usize = nums.len();

    while left < right {
        let mid: usize = (left + right) / 2;
        if nums[mid] < target {
            left = mid + 1;
        } else if nums[mid] > target {
            right = mid;
        } else {
            return mid as i32;
        }
    }

    return -1;
}

fn search2(nums: Vec<i32>, target: i32) -> i32 {
    let mut left: i32 = 0;
    let mut right: i32 = (nums.len() - 1) as i32;

    while left <= right {
        let mid = (left + right) / 2;
        if nums[mid as usize] < target {
            left = mid + 1;
        } else if nums[mid as usize] > target {
            right = left - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

#[cfg(test)]
mod tests {
    use crate::array::lc_704_binary_search::search1;
    use crate::array::lc_704_binary_search::search2;

    #[test]
    fn test_search1() {
        let nums: Vec<i32> = Vec::from([-1, 0, 3, 5, 9, 12]);
        let res: i32 = search1(nums, 9);
        assert_eq!(4, res);

        let nums: Vec<i32> = Vec::from([-1, 0, 3, 5, 9, 12]);
        let res: i32 = search1(nums, 2);
        assert_eq!(-1, res);

        let nums: Vec<i32> = Vec::from([5]);
        let res: i32 = search1(nums, 5);
        assert_eq!(0, res);
    }


    #[test]
    fn test_search2() {
        let nums: Vec<i32> = vec![-1, 0, 3, 5, 9, 12];
        let res: i32 = search2(nums, 9);
        assert_eq!(4, res);

        let nums: Vec<i32> = vec![-1, 0, 3, 5, 9, 12];
        let res: i32 = search2(nums, 2);
        assert_eq!(-1, res);

        let nums: Vec<i32> = vec![5];
        let res: i32 = search2(nums, -5);
        assert_eq!(-1, res);
    }
}