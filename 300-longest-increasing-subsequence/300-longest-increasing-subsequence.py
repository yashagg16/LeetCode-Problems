class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [1 for i in range(len(nums))]
        
        max_len = 1
        for i in range(len(nums)):
            # print("nums[i] ", nums[i])
            for j in range(i-1, -1, -1):
                # print("nums[j] ", nums[j])
                if(nums[j] < nums[i]) :
                    dp[i] = max(dp[j]+1, dp[i])
            # print(i, " ", dp[i])
            max_len = max(max_len, dp[i])
            
        
        return max_len
        