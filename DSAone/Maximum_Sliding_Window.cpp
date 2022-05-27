class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        deque<int> dq;
        int n = nums.size();
       // dq.push_front(nums[0]);
        for(int i = 0; i < k ; i++) {
             
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
          //  if (!dq.empty() && dq.peek_last() < nums[i])
              dq.push_back(i);
              cout << "Pushing :: " << nums[dq.front()] << endl;
        }
        
        
        ans.push_back(nums[dq.front()]);
         cout << "ans :: " << ans[0] << endl;
        for(int i = k ; i < n ; i++) {
            if (dq.front() == i-k) {
                dq.pop_front();
            }
             while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
             }
            
             dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        
       
        
        
        return ans;
        
        
    }
};
