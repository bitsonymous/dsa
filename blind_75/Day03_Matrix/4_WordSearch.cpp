class Solution {
public:
    int n , m;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    bool isValid(int i , int j){
        if(i >= 0 and i < n and j >= 0 and j<m) return true;
        else return false;
    }
    bool dfs(int i, int j,vector<vector<char>>& board, string &word, int idx, vector<vector<bool>> &vis){
        if(idx == word.size() - 1 and word[idx] == board[i][j]) return true;
        if(board[i][j] != word[idx]) return false;
        vis[i][j] = true;
        for(int k = 0; k<4; k++){
            int new_i = i + dx[k];
            int new_j = j + dy[k];
            if(isValid(new_i, new_j) and !vis[new_i][new_j]){
                if(dfs(new_i, new_j, board, word, idx+1, vis)){
                    return true;
                }
            } 
        }
        vis[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(),m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false)); 
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == word[0]){
                    if(dfs(i,j, board, word, 0, vis)) return true;
                }
            }
        }
        return false;
    }
};