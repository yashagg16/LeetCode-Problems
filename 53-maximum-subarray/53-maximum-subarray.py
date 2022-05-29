class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        maxSum = nums[0]
        currSum = nums[0]
        
        for i in range(1, n) : 
            currSum = max(currSum+nums[i], nums[i])
            maxSum = max(maxSum, currSum)
            
        return maxSum
        