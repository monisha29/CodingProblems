class Solution {

public :
    int dx[4] = {-1, 1, 0 , 0};
    int dy[4] = {0, 0 , -1 , 1};
    
public :
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int curr, int r , int c, int m , int n, string word) {
        visited[r][c] = true;
        
        if (curr == word.length())
            return true;
        
        if (curr > word.length())
            return false;
        
 
        
        for (int i = 0 ; i < 4 ; i++) {
            int x = r + dx[i];
            int y = c + dy[i];
            if ( x >= 0 && y >= 0 && x < m && y < n) {
                if (visited[x][y] == false && word.at(curr) == board[x][y]) {
                //    cout << word.at(curr) << endl;
                      if (dfs(board, visited, curr + 1 , x , y , m , n, word))
                          return true;
                }
            }
        }
        
        visited[r][c] = false;
        return false;
        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
         vector<vector<bool>> visited(m , vector<bool> (n, false));
        
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if (board[i][j] == word.at(0) && dfs(board, visited, 1, i , j , m , n , word))
                    return true;
            }
        }
        
        return false;
        
    }
};
