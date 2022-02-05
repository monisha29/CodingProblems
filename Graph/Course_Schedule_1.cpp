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
        
        in_stk[x] = 0;
    }
    
 public:
 void is_cyclic(int x, vector<vector<int>>& adj, vector<int>& visited, vector<int>& in_stk, bool& flag) {
     visited[x] = 1;
   //to track stack status , in a non-cyclic graph ans element cannot be present twice
     in_stk[x] = 1;
     
     
     for( auto y : adj[x]) {
         if (in_stk[y] == 1) {
             flag = true;
             break;
         }
         if (visited[y] == 0) {
             is_cyclic(y , adj, visited, in_stk, flag);
         }
     }
     
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
        vector<int> visited(numCourses, 0);
        vector<int> in_stk(numCourses,0);
        bool flag = false;
        for(int i = 0 ; i < numCourses ; i++) {
            if(visited[i] == 0) {
                is_cyclic(i , g, visited, in_stk, flag);
                if (flag)
                return false;
            }
        }
        
        if(!flag)
            return true;
        else
            return false;
        
    }
};


/*

[b,a] a->b
[1,0] 0->1



[1,0][0,1]

0->1
1->0




*/
