// DFS in a matrix

/*
1,1
1, -1
1, 0
-1, 1
-1, -1
-1, 0
0, 1
0, -1

*/
class Solution {
public :
    void dfs(vector<vector<int>>& isConnected, set<int>& visited, int x, int m) {
             visited.insert(x);
        
        set<int>::iterator vsi;
        for(int i = 0 ; i < m ; i++) {
            if (x != i) {
            vsi = visited.find(i);
            
            if (vsi == visited.end() && isConnected[x][i] == 1) {
                dfs(isConnected, visited, i , m);
                }
            }
        } 
    }   
            
        
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m = isConnected.size();
        int n = isConnected[0].size();
        
        set<int> visited;
        set<int>::iterator itr;
        int pro = 0;
        for(int i = 0 ; i < m ; i++) {
            itr = visited.find(i);
            if (itr == visited.end()) {
                //cout << "start with" << i << endl  ;
                dfs(isConnected, visited, i, m);
              // count only if not covered previously
                pro++;
                
            }
        }
        
        return pro;
    }
};

/*
1 0 0 
0 1 0 
0 0 1

*/

/*
1 - {2 , 3 ,4 }

*/

/*
  0 1 2
0 1 1 0
1 1 1 0
2 0 0 1
*/
