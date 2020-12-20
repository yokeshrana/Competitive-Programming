#include <bits/stdc++.h>
using namespace std;
#define n 5
bool isSafe(int i,int j){
    return i>=0&&i<=n-1&&j>=0&&j<=n-1;
}
void dfs(vector<vector<int>>  mt,int i,int j,int &count ,int visited[][n]){
    visited[i][j]=1;
    static int row[]={-1,-1,-1,0 ,0,1,1 ,1 };
    static int col[]={-1,0,1 ,-1,-1,-1 ,0,1};
    for(auto k=0;k<8;k++){
        if(isSafe(i+row[k],j+col[k])&&visited[i+row[k]][j+col[k]]==0&&mt[i+row[k]][j+col[k]]==1){
            count++;
            dfs(mt,i+row[k],j+col[k],count,visited);
        }
    }

}
int main()
{
    vector<vector<int>> mt{
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 1, 0, 0},
        {1, 1, 0, 1, 0},
    };
    int visited[n][n];
    int result=0;
    memset(visited, 0, sizeof visited);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (mt[i][j] == 1) 
                {
                    int count=1;
                    dfs(mt, i, j,count,visited);
                    result=max(result,count);
                }
        }
    cout << result<< endl;
    return 0;
}