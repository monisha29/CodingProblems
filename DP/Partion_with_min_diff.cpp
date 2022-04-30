//https://www.interviewbit.com/problems/minimum-difference-subsets/

int Solution::solve(vector<int> &nums) {
          int n = nums.size();
        vector<vector<int>> dp;
        
        int sum = 0;
        for(int i = 0 ; i < n ; i++) {
            sum = sum + nums[i];
        }
        
        
        
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
        
        int global_min = INT_MAX;
        for(int i = 0 ; i < sum+1 ; i++) {
            if (dp[n-1][i] == 1 && abs(i - abs(sum-i) < global_min))
                global_min = abs(i - abs(sum-i));
        }

        return global_min;
