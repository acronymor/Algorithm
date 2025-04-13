package algo

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

func bubbleSort(nums []int) []int {
	for i := 0; i < len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
			if nums[i] > nums[j] {
				nums[i], nums[j] = nums[j], nums[i]
			}
		}
	}
	return nums
}

func selectSort(nums []int) []int {
	for i := 0; i < len(nums); i++ {
		var selected int = i
		for j := i + 1; j < len(nums); j++ {
			if nums[j] < nums[selected] {
				selected = j
			}
		}
		nums[i], nums[selected] = nums[selected], nums[i]
	}
	return nums
}

func insertSort(nums []int) []int {
	for j := 1; j < len(nums); j++ {
		tmp := nums[j]
		var i = j - 1
		for i >= 0 && tmp < nums[i] {
			nums[i+1] = nums[i]
			i--
		}
		nums[i+1] = tmp
	}

	return nums
}

func quickSort(nums []int) []int {
	var find func(start, end int)
	var part func(start, end int) int

	find = func(start, end int) {
		if start > end {
			return
		}

		idx := part(start, end)
		find(start, idx-1)
		find(start+1, end)
	}

	part = func(start, end int) int {
		pivot := nums[start]
		for start < end {
			for start < end && nums[end] >= pivot {
				end--
			}
			nums[start] = nums[end]

			for start < end && nums[start] <= pivot {
				start++
			}
			nums[end] = nums[start]
		}

		nums[start] = pivot
		return start
	}

	find(0, len(nums)-1)

	return nums
}

func heapSort(nums []int) []int {
	var heapify func(i, n int)

	heapify = func(i, n int) {
		largest, left, right := i, 2*i+1, 2*i+2

		if left < n && nums[left] > nums[largest] {
			largest = left
		}

		if right < n && nums[right] > nums[largest] {
			largest = right
		}

		if largest != i {
			nums[i], nums[largest] = nums[largest], nums[i]
			heapify(largest, n)
		}
	}

	for i := len(nums) - 1; i >= 0; i-- {
		heapify(i, len(nums))
	}

	for i := len(nums) - 1; i >= 0; i-- {
		nums[0], nums[i] = nums[i], nums[0]
		heapify(0, i)
	}

	return nums
}
