class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++) 
            sum += nums[i];
        
        if (sum % 2 != 0)
            return false;
        
        sum = sum/2 ;
        
        
        int n = nums.size() ;
        
        vector<vector<int>> dp;
        
        for(int i = 0 ; i < n ; i++) {
            vector<int> vec(sum+1,0);
            dp.push_back(vec);
            
        }
        
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < sum + 1 ; j++) {
                if ( i == 0) {
                    if (nums[i] == j )
                        dp[0][j] = 1;
                else 
                    dp[0][j] = 0;
                } else {
                
                if (nums[i] > j) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    int val1 = 0;
                    if ( j - nums[i] > 0)
                        val1 = dp[i-1][j-nums[i]];
                    int val2 = dp[i-1][j];
                    
                    dp[i][j] = val1 || val2 ;
                }
                    
                    }
                
            }
        }
        
        
        return  dp[n-1][sum];
        
        
    }
};
