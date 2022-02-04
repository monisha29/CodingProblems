/*
Time limit exceeded for this solution 
*/
class Solution {
    
public : 
    void dfs(int x , vector<int>& visited, vector<vector<int>> g, vector<int>& op, vector<int>& in_stk, bool& flag) {
        visited[x] = 1;
        in_stk[x] = 1;
        for( auto y : g[x]) {
            if (in_stk[y] == 1) {
                flag = true;
                break;
            }
            if (!visited[y]) {
                dfs(y, visited, g, op, in_stk, flag);
            }
        }
          if (!flag)
          op.push_back(x);
        // to check for a cycle 
        in_stk[x] = 0;
    }
    
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>> g;
         for (int i = 0 ; i < numCourses ; i++) {
            vector<int> vec;
             g.push_back(vec);
        }
        for (int i = 0 ; i < prerequisites.size() ; i++) {
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> op;
        vector<int> visited(numCourses , 0);
           vector<int> in_stk(numCourses , 0);
        
        bool flag = false;
        for(int i = 0 ; i < numCourses ; i++) {
              if (flag)
            return false;
            if (visited[i] == 0 && !flag) {
                dfs(i, visited, g, op, in_stk, flag);
            }
        }
      
        if (op.size() == numCourses )
            return true;
        else
            return false;
        
    }
};
