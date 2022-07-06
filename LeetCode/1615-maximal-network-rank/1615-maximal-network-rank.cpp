class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> adjlist(n);
        for(auto x:roads){
            adjlist[x[0]].insert(x[1]);
            adjlist[x[1]].insert(x[0]);
        }
        int mxnwrank=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                int currRank=adjlist[i].size()+adjlist[j].size();
                if(adjlist[i].count(j))
                    currRank--;
                mxnwrank=max(mxnwrank,currRank);
            }
        return mxnwrank;
    }
};