class Solution {
public:
  bool isSafe(int i,int j,int p,int q,int r,int s){
      
      if((p==0&&q==0) || (p==-1&&q==-1) || (p==-1&&q==1) || (p==1&&q==-1) || (p==1&&q==1))
          return false;
            if(i+p>=0 && i+p<r && j+q >=0 && j+q <s)
                return true;
        return false;
        }
            
            
        void dfs(vector<vector<char>> &grid ,int i,int j,vector<vector<int>> &visited){
            
            for(int p=-1;p<2;p++){
                for(int q=-1;q<2;q++){
                    if(isSafe(i,j,p,q,grid.size(),grid[0].size())&& !visited[i+p][j+q]&&grid[i][j]=='1')
                    {
                        visited[i+p][j+q]=1;
                        dfs(grid,i+p,j+q,visited);
                        
                    }
                }
            }
            
        }
        
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>  visited(grid.size(),vector<int>(grid[0].size(),0));
        int count=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j]&&grid[i][j]=='1')
                {
                    visited[i][j]=0;
                    count++;
                    dfs(grid,i,j,visited);
                }
            }
                       return count;
        
    }
};