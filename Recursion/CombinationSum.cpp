class Solution {
public :
    void func(int i, int n, vector<int> tmp, vector<int>& cand, int target, set<vector<int>>& ans) {
        if (i == n) {
        if  (target == 0) {
            sort(tmp.begin(), tmp.end());
            ans.insert(tmp);
           
        }
             return;
        }
      // pick the current element
        if (target >= cand[i]) {
           // curr_sum = curr_sum + cand[i];
            tmp.push_back(cand[i]);
            // call same element multiyple times if it is worth adding value
            func(i,n,tmp,cand, target - cand[i],ans);
            tmp.pop_back();
        } 
      // do not pick the curr element
        func(i+1,n,tmp, cand, target,ans);
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        set<vector<int>> tmp_ans;
        func(0,n,tmp,candidates,target,tmp_ans);
        
        vector<vector<int>> ans;
        for(auto x : tmp_ans) {
            ans.push_back(x);
        }
        
        return ans;
    }
};
