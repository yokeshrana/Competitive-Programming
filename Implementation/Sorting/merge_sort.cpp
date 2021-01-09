#include <bits/stdc++.h>
using namespace std;

//merge Function assumes that v[low -> mid ] and v[mid+1 -> high] are two sorted array
//Function is similar to merging two sorted arrays
/*
We make two auxiallary copy 
first copy will contain  low ->  mid  elements
second copy will contain mid+1 -> high elements
then we will use auxillary array and place elements in original v array
OR
Make one auxillary array and sort and merge the array result in that and finally copy that array to  original array
 in a sorted fashion finally
*/
void merge(vector<int> &v, int low, int mid, int high)
{
    int temp[high - low + 1];          //Auxially arrya to hold sorted result of two
    int fs = low, ss = mid + 1, k = 0; // iterators fs first array  ss second array and k for temp array
    while (fs <= mid && ss <= high)    //when one of sub array completes it breaks
        if (v[fs] < v[ss])
            temp[k++] = v[fs++];
        else
            temp[k++] = v[ss++];
    while (fs <= mid)
        temp[k++] = v[fs++];
    while (ss <= high)
        temp[k++] = v[ss++];
    for (int i = low; i <= high; i++)
        v[i] = temp[i - low];
}
void mergeSort(vector<int> &v, int low, int high)
{
    if (low >= high) //It means we reached upto singe element ,single element is already sorted
        return;
    int mid = low + (high - low) / 2;
    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);
    merge(v, low, mid, high);
}
int main()
{
    vector<int> v{-2, 5, 6, 23, 12, 88, 3, 5, 7};
    mergeSort(v, 0, v.size() - 1);
    for (auto x : v)
    {
        cout << " " << x;
    }
    cout << endl;
    return 0;
}

// Complexity is O(nlogn)