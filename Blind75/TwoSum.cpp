class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
          map<int,int> mp;
          vector<pair<int,int>> arr;
         for(int i = 0 ; i < nums.size() ; i++ ) {
             arr.push_back(make_pair(nums[i], i));
             
         }
        vector<int> ans;
           sort(arr.begin(), arr.end());
            int low = 0 ; int high = nums.size() - 1 ;
                bool found = false;
                while(low<high) {
                 //   cout << nums[low] << " , " << nums[high] << endl;
                    if (arr[low].first + arr[high].first == target) {
                        ans.push_back(arr[low].second);
                        ans.push_back(arr[high].second);
                        break;
                    } else if (arr[low].first + arr[high].first > target) {
                       high--;
                    } else {
                        low++;
                    }
                }
        //  cout << mp.find(nums[low])->second << " , " << mp.find(nums[high])->second << endl;
        
        return ans;
        
    }
};
