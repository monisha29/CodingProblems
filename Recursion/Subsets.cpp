class Solution
{
    
    public:
    
    void p_s(int i , int n , vector<int> tmp, vector<vector<int>>& op, vector<int> A) {
        if (i == n) {
            return;
        } else {
            tmp.push_back(A[i]);
            op.push_back(tmp);
            p_s(i+1,n,tmp,op,A);
            tmp.pop_back();
            p_s(i+1,n,tmp,op,A);
        }
    }
    public:
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        vector<vector<int>> op;
        int n = A.size();
        vector<int> tmp;
        p_s(0,n,tmp, op, A);
        
        return op;
    }
};
