// RMQSQ - Range Minimum Query
//https://www.spoj.com/problems/RMQSQ/
/*
Sparse Table 
The idea is to precompute minimum of all subarrays of size 2j where j varies from 0 to Log n. We make a table table[i][j] such 
that table[i][j] contains minimum of range starting from i and of size 2^j. 
For example lookup[0][3] contains minimum of range [0, 7] (starting with 0 and of size 23)
*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005; //Max value of the array
const int MAXLGN = 18;
int RMQ[MAXN][MAXLGN]; // ie 2^500 is the  Length of the max inteval ,ie max inteval u wanna conver)

int log(int i)
{
    int ret = 0;

    while ((i = i >> 1))
    {
        ++ret;
    }
    return ret;
}

int query(int i, int j)
{
    int len = j - i + 1;
    int exponent = log(len);

    return min(
        RMQ[i][exponent],
        RMQ[j + 1 - (1 << exponent)][exponent]);
}

void buildSparseTable(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        RMQ[i][0] = nums[i]; //for length as 2^0 =1 so here sum is element only
    }
    for (int j = 1; (1 << j) <= nums.size(); j++)                           // ie compute the intervals of legnth 2^1 2^2 - - --- 2^j<nums.size();
        for (int i = 0; i + (1 << j) <= nums.size(); i++)                   // here we the provide the range start pt
            RMQ[i][j] = min(RMQ[i][j - 1], RMQ[i + (1 << (j - 1))][j - 1]); //Define ur function here her eit is minimum so min
}
int main()
{
    int n;
    cin >> n;
    vector<int> num;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        num.push_back(t);
    }
    buildSparseTable(num);
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << query(a, b) << endl;
    }

    return 0;
}