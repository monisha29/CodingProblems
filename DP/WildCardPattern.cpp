class Solution {
public:
    bool isMatch(string str, string pattern) {
         int col = str.length();
        int row = pattern.length();
        
 // vector<vector<int>> dp(n+1,vector<int>(W+1,0));

        vector<vector<int>> dp(row+1 , vector<int>(col + 1, false ));
        
        dp[0][0] = 1;
        
        
        for(int i = 1 ; i <= row ; i++) {
            if (pattern.at(i-1) == '*' )
                dp[i][0] = dp[i-1][0];
        }
        
        
        for(int i = 1 ; i <= row ; i++) {
            char pv = pattern.at(i-1);
            for(int j = 1 ; j <= col ; j++) {
                char sv = str.at(j-1);
                if (pv == '*') {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j-1] || dp[i-1][j];
                } else if (pv == '?' || pv == sv ) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        
        // for(int i = 0 ; i <= row ; i++) {
        //     for(int j = 0 ; j <= col ; j++) {
        //         cout << dp[i][j] << " , " ;
        //     }
            
        //     cout << endl;
        // }
        
        return dp[row][col];
    }
};
