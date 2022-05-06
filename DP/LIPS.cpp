class Solution {
public:
     int lcs(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        
        for(int i = 1 ; i <= n1 ; i++) {
            char rowch = text1.at(i-1);
            for(int j = 1 ; j <= n2 ; j++) {
                char colch = text2.at(j-1);
               
                if ( rowch == colch ) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    // cout << rowch << " " << colch << endl;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n1][n2];
        
     }
public:
    int longestPalindromeSubseq(string s) {
        string str2 = s;
        reverse(str2.begin(), str2.end());
        return lcs(s, str2);
    }
};

// https://leetcode.com/problems/longest-palindromic-substring/
