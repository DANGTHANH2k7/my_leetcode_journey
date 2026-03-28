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
                // Chỉ bắt đầu đệ quy nếu ký tự đầu tiên khớp
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
        // Điều kiện dừng: đã tìm thấy toàn bộ chuỗi
        if (k == word.length()) 
        {
            return true;
        }

        // Kiểm tra biên, ô đã dùng, hoặc ký tự không khớp
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || 
            board[r][c] == '\0' || board[r][c] != word[k]) 
        {
            return false;
        }

        // Đánh dấu ô đã dùng bằng cách tạm thời thay đổi giá trị của nó
        // Cách này giúp tiết kiệm bộ nhớ hơn là dùng mảng bool used[10][10]
        char temp = board[r][c];
        board[r][c] = '\0'; 

        // Thử 4 hướng
        bool found = backtrack(board, word, r + 1, c, k + 1) ||
                     backtrack(board, word, r - 1, c, k + 1) ||
                     backtrack(board, word, r, c + 1, k + 1) ||
                     backtrack(board, word, r, c - 1, k + 1);

        // Trả lại ký tự cũ (Backtrack)
        board[r][c] = temp;

        return found;
    }
};