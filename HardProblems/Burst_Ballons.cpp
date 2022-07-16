// Consider the path when you want to burst a balloon at the last
// i to j represents the range inside which you can burst balloons
// so for example : 3 1 5 8
/*
 i = 0 to j = 0 ==> you can burst balloons starting from i to j , where you choose the last ballon you want to burst
 Why we take last ballons so that we can get the outside values to multiply i.e if i chose in burst 3 last in (3) 1 5 8
 i will know its left multiplier will be 1 and right multiplier will be 1
 for eg : 3 (1 5) 8
 here is we choose to burst 5 last its means all other balloons inside i to j have already been burst so the array must have become 3 (5) 8
 so our left and right multipliers will be 3 and 8
 
 k is the balloon we choose oto burst 
 so in 3 (1 5) 8
 k will be 1 then k will be 5 , we will then choose the best result
 dp equation : dp[i][j] = max( left_muliplier* nums[k] * right_multiplier + dp[i][k-1] + dp[k+1][j] 
*/

class Solution {
  
public:
    int maxCoins(vector<int>& nums) {
        
        
        int n = nums.size() ;
        
        vector<vector<int>> dp(n, vector<int>(n+1,0));
        
        // for(int i = 0 ; i < n ;i++) {
        //     dp[i][i] = nums[i];
        // }
        
        for(int l = 1 ; l <= n ; l++) {
            for(int i = 0 ; i <= n-l; i++) {
                int j = i + l - 1;
                int l = 1;
                int r = 1;
                if(i-1 >= 0)
                    l = nums[i-1];
                
                if(j+1 < n)
                     r = nums[j+1];
                for(int k = i ; k <= j ; k++) {
                    int l_s = 0;
                    int r_s = 0;
                   
                    
                    if(k - 1 >= 0 && i != k)
                        l_s = dp[i][k-1];
                    if (j != k && k+1 < n )
                        r_s = dp[k+1][j];
            
                    dp[i][j] = max(dp[i][j], nums[k]*l*r + l_s + r_s); 
                }
                
                //  cout << i << " " << j << " "<< dp[i][j] <<endl;
                
                
            }
        }
        
        return dp[0][n-1];
    }
};
