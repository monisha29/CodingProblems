int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int> dp(n+1, 0);
	dp[1] = price[0];
	
	for(int i = 2 ; i <= n ; i++) {
		int val1 = price[i-1];
		for(int j = i-1 ; j > 0 ; j--) {
			if ( i - j > 0) {
				if (dp[i-j] + dp[j] > val1) {
					val1 = dp[i-j] + dp[j];
				}
			}
		}
		dp[i] = val1;
	}
	
	return dp[n];
}
//https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
