class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        
        for(int i=0;i<grid[0].size();i++){
            if(grid[0][i]==1)
            {
                for(int j=0;j<grid.size();j++)
                    grid[j][i]=! grid[j][i];
            }
        }
          for(int i=0;i<grid.size();i++){
            int sum=0;
                for(int j=0;j<grid[0].size();j++)
                    sum+=grid[i][j];
              if(!(sum==0||sum==grid[0].size()))
                  return false;
            }
            return true;
        }
    
};