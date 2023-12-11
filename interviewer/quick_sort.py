
def quick_sort(nums):
	if nums:
		mid = nums[0]
		left_arr = [x for x in nums[1:] if x < mid]
		right_arr = [x for x in nums[1:] if x >= mid]
		return quick_sort(left_arr) + [mid] + quick_sort(right_arr)
	return []

nums = []
print(quick_sort(nums))

