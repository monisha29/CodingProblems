int findWays(vector<int> &nums, int sum)
{
    // Write your code here.
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
                } else if (nums[i] == j) {
			       dp[i][j] = dp[i-1][j] + 1; 			
				} else {
                    int val1 = 0;
                    if ( j - nums[i] >= 0)
                        val1 = dp[i-1][j-nums[i]];
                    int val2 = dp[i-1][j];
                    
                    dp[i][j] = val1 + val2 ;
                }
                    
                    }
                
            }
        }
	
	    
//         for(int i = 0 ; i < n ; i++) {
//             for(int j = 0 ; j < sum + 1 ; j++) {
// 				cout << dp[i][j] << " , " ;
// 			}
			
// 			cout << endl;
// 		}
	
	return dp[n-1][sum];
}
 
/*
  0 1 2 3
1 0 1 0 0 
2 0 1 1
2
3
*/
	  
	  
/* if take
    when subracting arr[i] from j gives some value 
	
	if  not take
	carry from above 
	
*/	  
