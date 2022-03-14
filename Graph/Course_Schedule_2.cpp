https://leetcode.com/problems/course-schedule-ii/submissions/
/*
Applicaton of topological Sorting

*/
class Solution {
    
public : 
    bool dfs(int x , vector<vector<int>>& adj, vector<int>& visited, vector<int>& in_stack, vector<int>& op) {
        visited[x] = 1;
        in_stack[x] = 1;
        
        for(auto y : adj[x]) {
            if (in_stack[y] == 1) {
                return true;
            }
            if ( visited[y] == 0) {
                if(dfs(y, adj, visited, in_stack,op) == true)
                    return true;
            }
        }
        
        in_stack[x] = 0;
        op.push_back(x);
        return false;
    }
    
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*build a graph*/
        vector<vector<int>> adj ; 
        
        for(int i = 0 ; i < numCourses ; i++) {
            vector<int> vec;
            adj.push_back(vec);
        }
        
        
        for (int i = 0 ; i < prerequisites.size() ; i++) {
             adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> visited(numCourses, 0);
        vector<int> in_stk(numCourses, 0);
        /* check for a cycle*/
        vector<int> op;
        bool cycle = false;
        for(int i = 0 ; i < numCourses ; i++) {
            if (visited[i] == 0 && cycle == false) {
                cycle = dfs(i, adj, visited, in_stk, op);
            }
            if(cycle)
                break;
        }
        
        
        if (cycle)
            op.clear();
        /* topologically sort */
         reverse(op.begin(), op.end());
        return op;
    }
};
