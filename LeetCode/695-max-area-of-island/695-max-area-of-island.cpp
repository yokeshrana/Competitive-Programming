class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int maxarea=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j]&&grid[i][j]==1)
                maxarea=max({traverse(grid,visited,i,j),maxarea});
            }
        return maxarea;
    }
    
    int traverse(vector<vector<int>>& grid,vector<vector<int>>& visited,int r,int c){
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() ||
                visited[r][c] || grid[r][c] == 0)
            return 0;
        visited[r][c] = 1;
        return (1 + traverse(grid,visited,r+1, c) + traverse(grid,visited,r-1, c)
                  + traverse(grid,visited,r, c-1) + traverse(grid,visited,r, c+1));
        
    }
};