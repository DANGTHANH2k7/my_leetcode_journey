class Solution 
{
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (board[i][j] == word[0]) 
                {
                    if (backtrack(board, word, i, j, 0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool backtrack(vector<vector<char>>& board, string& word, int r, int c, int k) {
        if (k == word.length()) 
        {
            return true;
        }

        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || 
            board[r][c] == '\0' || board[r][c] != word[k]) 
        {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '\0'; 

        bool found = backtrack(board, word, r + 1, c, k + 1) ||
                     backtrack(board, word, r - 1, c, k + 1) ||
                     backtrack(board, word, r, c + 1, k + 1) ||
                     backtrack(board, word, r, c - 1, k + 1);

        board[r][c] = temp;

        return found;
    }
};
