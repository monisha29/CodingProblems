
// this approach takes O(n) space
class Solution {
public :
    void dfs(TreeNode* root, vector<int>& op) {
        if (root) {
            dfs(root->left, op);
            op.push_back(root->val);
            dfs(root->right, op);
        }
    }
        
public:
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        bool op = true;
        for(int i = 1 ; i < ans.size() ; i++) {
            if (ans[i-1] >= ans[i])
                return false;
        }
        
        return true;
        
    }
};
// Second approach 
// root value should be greator than all elements of a tree in left and smaller than all elements in the right

class Solution {
public:
bool valid(TreeNode* root,long long mini,long long maxi){
    if(root==NULL) return true;
    if(root->val>=maxi || root->val<=mini) return false; //out of range -> return false; 
    
    return valid(root->left,mini,root->val) && valid(root->right,root->val,maxi);
}
    
    bool isValidBST(TreeNode* root) {
        return valid(root,-1e12,1e12);
    }
};
