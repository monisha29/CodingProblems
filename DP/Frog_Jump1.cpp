int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
	vector<int> dp(n,0);
	
	if(n >= 1) {
		dp[1] = abs(heights[1] - heights[0]);
		
		if (n == 1) {
			return dp[1];
		}
		
		for(int i = 2 ; i < n ; i++) {
			int val1 = dp[i-1] + abs(heights[i] - heights[i-1]);
			int val2 = dp[i-2] + abs(heights[i] - heights[i-2]);
			
			dp[i] = val1 < val2 ? val1 : val2 ;
		}
		
		
		return dp[n-1];
		
		
		
	}
	
	
}
