///
/// # 在排序数组中查找元素的第一个和最后一个位置
///
/// ## 描述
/// 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
/// 如果数组中不存在目标值 target，返回 [-1, -1]。
/// 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
///
/// ## 示例
/// 输入：nums = [5,7,7,8,8,10], target = 8
/// 输出：[3,4]
///
///  输入：nums = [5,7,7,8,8,10], target = 6
///  输出：[-1,-1]
///
/// ## 链接
/// [leetcode-34](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/)
///
///
fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
    fn search_left(nums: &Vec<i32>, target: i32) -> i32 {
        let mut left = 0;
        let mut right = nums.len();
        let mut res = 0;
        while left < right {
            let mid = (left + right) / 2;
            if nums[mid] < target {
                left = mid + 1;
            } else {
                res = mid;
                right = mid;
            }
        }

        return if nums.is_empty() || nums[res] != target { -1 } else { res as i32 };
    }
    fn search_right(nums: &Vec<i32>, target: i32) -> i32 {
        let mut left = 0;
        let mut right = nums.len();
        let mut res = 0;
        while left < right {
            let mid = (left + right) / 2;
            if nums[mid] <= target {
                res = mid;
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return if nums.is_empty() || nums[res] != target { -1 } else { res as i32 };
    }

    let left: i32 = search_left(&nums, target);
    let right: i32 = search_right(&nums, target);

    return vec![left, right];
}


#[cfg(test)]
mod tests {
    use crate::array::lc_34_find_positions::search_range;

    #[test]
    fn test_search_range() {
        let nums: Vec<i32> = vec![5, 7, 7, 8, 8, 10];
        let target: i32 = 8;
        let res: Vec<i32> = search_range(nums, target);
        assert_eq!(vec![3, 4], res);

        let nums: Vec<i32> = vec![5, 7, 7, 8, 8, 10];
        let target: i32 = 6;
        let res: Vec<i32> = search_range(nums, target);
        assert_eq!(vec![-1, -1], res);

        let nums: Vec<i32> = vec![];
        let target: i32 = 0;
        let res: Vec<i32> = search_range(nums, target);
        assert_eq!(vec![-1, -1], res);
    }
}