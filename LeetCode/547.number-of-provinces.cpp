/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int FindParentGp(int x, vector<int> &gpOf)
    {
        return gpOf[x] == x ? x : FindParentGp(gpOf[x], gpOf);
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        //Using Union Find Algorithm
        /* 
       Intially we assume that there are n groups and 
       we fill like this gp[i]=i  ie each element contains in one gp and store total groups some where as N
       then we iterate through isConnected matrix and wherever edges are connected
       we will modify the relation of gp[x]to its new connection and decrement total groups as we formed one connection
        */
        int totalGroup = isConnected.size();  //assumption
        vector<int> gpOf(isConnected.size()); //vector that is used to map element to corresponding gp
        for (int i = 0; i < gpOf.size(); i++)
            gpOf[i] = i;
        int p, q;
        for (int i = 0; i < isConnected.size(); i++)
        {
            for (int j = i + 1; j < isConnected[0].size(); j++)
            {
                if (isConnected[i][j])
                {
                    p = FindParentGp(i, gpOf);
                    q = FindParentGp(j, gpOf);
                    if (p != q)
                    {
                        gpOf[q] = p;
                        totalGroup--;
                    }
                }
            }
        }
        return totalGroup;
    }
};
// @lc code=end
