package graph

import "container/list"

/**
 * @brief 课程表
 *
 * @details
 * 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
 * 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
 *
 * 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
 * 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
 *
 * @par 示例
 *
 * 示例 1
 * 输出：true
 * 输出：1
 *
 * 示例 2
 * 输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
 * 输出：false
 *
 * @see [leetcode-207](https://leetcode.cn/problems/course-schedule/)
 */

func canFinish(numCourses int, prerequisites [][]int) bool {
	var graph map[int][]int = make(map[int][]int, numCourses)
	var inDegree []int = make([]int, numCourses)

	for _, course := range prerequisites {
		inDegree[course[0]]++
		graph[course[1]] = append(graph[course[1]], course[0])
	}

	queue := list.New()
	for course := 0; course < numCourses; course++ {
		if inDegree[course] == 0 {
			queue.PushBack(course)
		}
	}

	var cnt int = 0
	for queue.Len() != 0 {
		top := queue.Front()
		queue.Remove(top)
		cnt += 1

		for _, course := range graph[top.Value.(int)] {
			inDegree[course]--
			if inDegree[course] == 0 {
				queue.PushBack(course)
			}
		}
	}

	return cnt == numCourses
}
