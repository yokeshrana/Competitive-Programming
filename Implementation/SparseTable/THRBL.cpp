//https://www.spoj.com/problems/THRBL/
#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1000000000;
const long long MAXLGN = 20;
long long int table[MAXN][MAXLGN];

void buildSparseTable(vector<int> &nums)
{
    for (long long int i = 0; i < nums.size(); i++)
        table[i][0] = nums[i];

    for (long long int j = 1; (1 << j) <= nums.size(); j++)            //length of range
        for (long long int i = 0; i + (1 << j) - 1 < nums.size(); i++) //starting index
        {
            table[i][j] = max(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
}
long long int log(long long int i)
{
    long long int ret = 0;

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
    return max(table[i][j - 1], table[j + 1 - (1 << exponent)][exponent]);
}
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        nums.push_back(t);
    }
    buildSparseTable(nums);
    int count = 0;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        count += (query(min(l, r), max(l, r) - 1) == nums[l]);
    }
    cout << count << endl;
    return 0;
}