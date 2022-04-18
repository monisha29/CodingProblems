class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        map<int, int>::iterator mpi;
        int curr_sum=0,ans=0;
        mp[curr_sum] = 1;
        for(int i = 0 ; i < nums.size() ; i++) {
            curr_sum+= nums[i];
            int extra = curr_sum - k ;
            mpi = mp.find(extra);
            if (mpi != mp.end()) {
                ans = ans + mpi->second ;
            }
            mp[curr_sum] = mp[curr_sum] + 1;
        }
        return ans;
    }
};
