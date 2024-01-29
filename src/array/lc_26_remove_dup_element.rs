///
/// # 删除有序数组中的重复项
///
/// ## 描述
/// 给你一个升序排列的数组 nums ，请你原地删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
/// 元素的相对顺序 应该保持 一致 。
///
/// ## 示例
/// 输入：nums = [1,1,2]
/// 输出：2, nums = [1,2,_]
/// 解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
///
/// 输入：nums = [0,0,1,1,1,2,2,3,3,4]
/// 输出：5, nums = [0,1,2,3,4]
/// 解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。
///
/// ## 链接
/// [leetcode-26](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/)
///

fn remove_duplicates1(nums: &mut Vec<i32>) -> i32 {
    let mut j: usize = 1;
    for i in 0..nums.len() {
        if nums[i] != nums[j - 1] {
            nums[j] = nums[i];
            j += 1;
        }
    }
    return j as i32;
}

fn remove_duplicates2(nums: &mut Vec<i32>) -> i32 {
    nums.dedup();
    nums.len() as i32
}

#[cfg(test)]
mod tests {
    use crate::array::lc_26_remove_dup_element::{remove_duplicates1, remove_duplicates2};

    #[test]
    fn test_remove_dup_element1() {
        let mut nums: Vec<i32> = vec![1, 1, 2];
        let res: i32 = remove_duplicates1(&mut nums);
        assert_eq!(2, res);

        let mut nums: Vec<i32> = vec![0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
        let res: i32 = remove_duplicates1(&mut nums);
        assert_eq!(5, res);

        let mut nums: Vec<i32> = vec![1, 1];
        let res: i32 = remove_duplicates1(&mut nums);
        assert_eq!(1, res);
    }


    #[test]
    fn test_remove_dup_element2() {
        let mut nums: Vec<i32> = vec![1, 1, 2];
        let res: i32 = remove_duplicates2(&mut nums);
        assert_eq!(2, res);

        let mut nums: Vec<i32> = vec![0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
        let res: i32 = remove_duplicates2(&mut nums);
        assert_eq!(5, res);

        let mut nums: Vec<i32> = vec![1, 1];
        let res: i32 = remove_duplicates2(&mut nums);
        assert_eq!(1, res);
    }
}