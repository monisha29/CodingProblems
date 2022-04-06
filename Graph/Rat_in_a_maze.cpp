https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1


class Solution{
    
public :
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
public:
    void dfs(int r , int c, vector<vector<int>>& visited,vector<vector<int>> &m, int N , string& op, vector<string>& ans) {
        
        if ( r == N-1 && c == N-1) {
            ans.push_back(op);
        } else {
        
        for(int i = 0 ; i < 4 ; i++) {
            int x = r + dx[i];
            int y = c + dy[i];
            if (x >= 0 && y >= 0 && x <= N-1 && y <= N-1 && visited[x][y] == 0 && m[x][y] == 1) {
                visited[x][y] = 1;
               // cout << "At :: " << x << " , " << y << endl;
                string dir = "";
                if (i == 0)
                    dir = "U";
                else if (i == 1) 
                    dir = "D";
                else if (i == 2)
                    dir = "L";
                else if (i == 3)
                    dir = "R";
                op = op + dir ;
               // cout << " Adding dir " << dir << " op :: " << op << endl ;
                dfs(x,y,visited,m, N, op, ans);
                op.pop_back();
                visited[x][y] = 0;
             //   cout << "Removing dir " << dir << " op :: " << op << endl ;
            }
        }
        }
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> visited;
        
        for(int i = 0 ;  i < n ; i++) {
            vector<int> tmp(n,0);
            visited.push_back(tmp);
        }
        vector<string> ans;
        string op = "";
        visited[0][0] = 1;
        if (m[0][0])
        dfs(0,0,visited,m,n,op,ans);
        
        return ans;
    }
};
