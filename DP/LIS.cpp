class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n,1);
        int global_max = 1;
        for(int i = 1 ; i < n ; i++) {
            int max = 1;
            for(int j = i-1 ; j >=0 ; j--) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > max) {
                        max = dp[j] + 1;
                    }
                }
            }
         //   
            dp[i] = max;
           // cout << i  << " :: " << dp[i]  << endl ;
            
            if (dp[i] > global_max)
                global_max = dp[i];
        }
        
        return global_max;
    }
};
