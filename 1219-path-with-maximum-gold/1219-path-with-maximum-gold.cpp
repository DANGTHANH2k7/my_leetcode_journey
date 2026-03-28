class Solution
{
private:
  int m, n;
  int maxGold = 0;
  int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
  void Try(int row, int col, int currentGold, vector<vector<int>>& grid)
  {
    maxGold = max(maxGold, currentGold);
    int temp = grid[row][col];
    grid[row][col] = 0;
    for(int i = 0; i < 4; i++)
    {
      int nr = row + dx[i], nc = col + dy[i];
      if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] > 0)
      {
        Try(nr, nc, currentGold + grid[nr][nc], grid);
      }
    }
    grid[row][col] = temp;
  }
public:  
  int getMaximumGold(vector<vector<int>>& grid) 
  {
    maxGold = 0;
    m = grid.size(), n = grid[0].size();
    for(int i = 0; i < m; i++)
    {
      for(int j = 0; j < n; j++)
      {
        if(grid[i][j])
        {
          Try(i, j, grid[i][j], grid);
        }
      }
    }  
    return maxGold;      
  }
};