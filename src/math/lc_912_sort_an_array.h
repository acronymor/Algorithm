#include <iostream>
#include <vector>

/**
 * @namespace math
 * @brief 排序数组
 */

namespace algo {
namespace math {
/**
 * @brief 排序数组
 *
 * @details
 * 给你一个整数数组 nums，请你将该数组升序排列。
 *
 * @par 示例
 *
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 *
 * 输入：nums = [5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 *
 * @see [leetcode-912](https://leetcode.cn/problems/sort-an-array/)
 */

class SortArray {
 public:
  /**
   * @ingroup bubble-sort
   */
  std::vector<int> bubbleSort(std::vector<int>& nums) {
    for (size_t i = 0; i < nums.size(); i++) {
      for (size_t j = i + 1; j < nums.size(); j++) {
        if (nums[i] > nums[j]) {
          std::swap(nums[i], nums[j]);
        }
      }
    }
    return nums;
  }

  /**
   * @ingroup quick-sort
   */
  std::vector<int> quickSort(std::vector<int>& nums) {
    if (nums.size() < 2) {
      return nums;
    }

    quickSortHelper(nums, 0, nums.size() - 1);
    return nums;
  }

  void quickSortHelper(std::vector<int>& nums, int start, int end) {
    if (start > end) {
      return;
    }

    size_t tmp = partition(nums, start, end);
    quickSortHelper(nums, start, tmp - 1);
    quickSortHelper(nums, tmp + 1, end);
  }

  int partition(std::vector<int>& nums, int start, int end) {
    int pivot = nums[start];

    while (start < end) {
      while (start < end && nums[end] >= pivot) {
        end--;
      }
      nums[start] = nums[end];

      while (start < end && nums[start] <= pivot) {
        start++;
      }
      nums[end] = nums[start];
    }

    nums[start] = pivot;
    return start;
  }

  /**
   * @ingroup selection-sort
   */
  std::vector<int> selectSort(std::vector<int>& nums) {
    for (size_t i = 0; i < nums.size(); i++) {
      int minIdx = i;
      for (size_t j = i + 1; j < nums.size(); j++) {
        if (nums[j] <= nums[minIdx]) {
          minIdx = j;
        }
      }

      std::swap(nums[i], nums[minIdx]);
    }
    return nums;
  }

  /**
   * @ingroup heap-sort
   */
  std::vector<int> heapSort(std::vector<int>& nums) {
    if (nums.size() < 2) {
      return nums;
    }

    // build heap
    for (int i = nums.size() - 1; i >= 0; i--) {
      heapify(nums, nums.size(), i);
    }

    // adjust heap
    for (int i = nums.size() - 1; i >= 0; i--) {
      std::swap(nums[i], nums[0]);

      heapify(nums, i, 0);
    }

    return nums;
  }

  void heapify(std::vector<int>& nums, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && nums[left] > nums[largest]) {
      largest = left;
    }

    if (right < n && nums[right] > nums[largest]) {
      largest = right;
    }

    if (largest != i) {
      std::swap(nums[largest], nums[i]);
      heapify(nums, n, largest);
    }
  }

  /**
   * @ingroup insert-sort
   */
  std::vector<int> insertSort(std::vector<int>& nums) {
    for (size_t j = 1; j < nums.size(); j++) {
      int temp = nums[j];
      int i = j - 1;

      while (i >= 0 && temp < nums[i]) {
        nums[i + 1] = nums[i];
        i--;
      }

      nums[i + 1] = temp;
    }

    return nums;
  }
};
}  // namespace math
}  // namespace algo