#include <stdc++.h>
using namespace std;
// 1 .Generate all String of n bits
void generate(vector<char> &a, int i, int n)
{
    if (i == n)
    {
        for (auto x : a)
            cout << x;
        cout << endl;
    }
    else
    {
        a[i] = '0';
        generate(a, i + 1, n);
        a[i] = '1';
        generate(a, i + 1, n);
    }
}
int main()
{
    //1
    int n = 3;
    vector<char> v(n);
    generate(v, 0, n);
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