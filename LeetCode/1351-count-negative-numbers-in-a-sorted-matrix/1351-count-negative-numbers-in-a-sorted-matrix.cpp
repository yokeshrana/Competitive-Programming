class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0,oe=grid.size(),ie=grid[0].size();
        int total=oe*ie;
        for(int i=0;i<oe;i++){
            for(int j=0;j<ie;j++){
                if(grid[i][j]>=0)
                {
                    count++;
                }else
                {
                    ie=j--;
                }
            }
        }
        return total-count;
    }
};