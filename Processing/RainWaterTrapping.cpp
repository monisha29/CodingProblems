//https://leetcode.com/problems/trapping-rain-water/submissions/

/*
get the blocking wall from left side and right side for every height

*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ;
        
        vector<int> left_blocker(n,0);
        vector<int> right_blocker(n,0);
        
        left_blocker[0] = height[0];
        for(int i = 1 ; i < n ; i++) {
         if (height[i] < left_blocker[i-1]) {
                left_blocker[i] = left_blocker[i-1];
            } else {
                 left_blocker[i] = height[i];
            }
            
            // cout << left_blocker[i] << endl;
        }
        right_blocker[n-1] = height[n-1];
     //   cout << "_______________" << endl ;
        for(int i = n-2 ; i > 0 ; i--) {
            if (height[i] < right_blocker[i+1]) {
                right_blocker[i] = right_blocker[i+1];
            } else {
                 right_blocker[i] = height[i];
            }
            
      //     cout << right_blocker[i] << endl;
        }
        
        int ans = 0 ;
        
        for (int i = 1 ; i <= n-2 ; i++) {
            ans = ans + abs(height[i] - min(left_blocker[i], right_blocker[i]));
        }
        
        return ans;
        
    }
};
