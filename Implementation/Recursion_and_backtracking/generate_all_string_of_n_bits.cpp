#include <stdc++.h>
using namespace std;
// 1 .Generate all String of n bits
void generate(vector<int> &a, int i, int n, int k)
{
    if (i == n)
    {
        for (auto x : a)
            cout << x;
        cout << endl;
    }
    else
    {
        for (int j = 0; j < k; j++)
        {
            a[i] = j;
            generate(a, i + 1, n, k);
        }
    }
}
int main()
{
    //1
    int n = 3;
    int k = 2; //means string can be formed using 0,1,2,3 as we are drawing 0--k-1
               //Question can be further extending if they want some specific chanracter string
    vector<int> v(n);
    generate(v, 0, n, k);
    return 0;
}

// 000
// 001
// 010
// 011
// 100
// 101
// 110
// 111