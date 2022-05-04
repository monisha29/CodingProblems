class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0)
            return 1;
        int n = coins.size();
        
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        
        
        for(int i = 1 ; i <= n ; i++) {
            int coin = coins[i-1];
            for(int j = 1 ; j <= amount ; j++) {
                int take = 0 ; int nottake = 0;
                
                // if ( i == 1 ) {
                //     if ( coin == 1) {
                //         take = 1;
                //     } else if ( j == coin) {
                //         take = 1;
                //     }
                // }
                
                if (j > coin) {
                    take =  dp[i][j-coin];
                } else if ( j == coin) {
                    take = 1;
                }
                
                
                nottake = dp[i-1][j];
                dp[i][j] = take + nottake ;
            }
        }
        
        // for(int i = 1 ; i <= n ; i++) {
        //     for(int j = 1 ; j <= amount ; j++) {
        //         cout << dp[i][j] << " , " ;
        //     }
        //     cout << endl;
        // }
        
        return dp[n][amount];
    }
};
