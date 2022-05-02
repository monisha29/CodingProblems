//https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=1
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
	if (x == 0)
		return 0;
	int n = num.size();
	vector<vector<int>> dp(n+1,vector<int>(x+1,INT_MAX));
	//vector<vector<int>> dp(n+1, vector<int>(W+1,0));
	
	//std::sort(num.begin() , num.end());
	for(int i = 1 ; i <= n ; i++) {
		int item = num[i-1];
		for(int j = 1 ; j <= x ; j++) {
			int take = INT_MAX ; int nottake = INT_MAX;
			if (j == item) {
				take = 1;
			} else if ( j > item && dp[i][j-item] != INT_MAX && dp[i][j-item] >= 0 ) {
				take = dp[i][j-item] + 1;
			}
			if (dp[i-1][j] != INT_MAX && dp[i-1][j] >= 0)
				nottake = dp[i-1][j];

			if (take == INT_MAX && nottake == INT_MAX)
				dp[i][j] = -1;
			else {
				dp[i][j] = min(take,nottake);
			}
		}
	}
	
	
	if (dp[n][x] == INT_MAX || dp[n][x] == -1)
		return -1;
	else
		return dp[n][x];
	
}
