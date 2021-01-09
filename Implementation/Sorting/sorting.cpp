#include <bits/stdc++.h>
using namespace std;
class Sorting
{
private:
    vector<int> v, b;

public:
    Sorting(vector<int> t)
    {
        v = t;
        b = t;
    }
    void BubbleSort();
    void InsertionSort();
    void SelectionSort();
    void Print();
};
void Sorting::Print()
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    v = b;
    cout << endl;
}
void Sorting::BubbleSort()
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - i - 1; j++) //To Reduce the extra swaps added v.size()-i as as in every outer loop max is moved to last ever time
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]); //Swapping adjancent elements ie max is moving to end
        }
        /* 
Best Case :: When array is sorted in increasing order so no swaps O(n)
Worst Case :: When array is reverse Sorted O(n^2)
Sorting In Place: Yes
Stable: Yes
         */
    }
}
void Sorting::SelectionSort()
{
    int min;
    for (int i = 0; i < v.size(); i++)
    {
        min = i; //Find the min element index
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[min])
                min = j;
        }
        swap(v[i], v[min]);
        /* 
Best Case :: Aleardy Sorted O(n)
Worst Case :: When array is reverse Sorted O(n^2)
Sorting In Place(ie Dont require extra space): Yes
Stable : Yes
        
         */
    }
}
void Sorting::InsertionSort()
{
    //Maintain Two Subarray Sorted and Unsorted ,Pick element from unsordted and place at adewquate location in unsorted
    int j = 0, temp;
    for (int i = 1; i < v.size(); i++)
    {
        j = i - 1;
        temp = v[i];
        while (j >= 0 && v[j] > temp)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = temp;
    }

    /* 
Best Case :: Aleardy Sorted O(n)
Worst Case :: When array is reverse Sorted O(n^2)
Sorting In Place(ie Dont require extra space): Yes
Stable : Yes  
         */
}

int main()
{
    Sorting s({1, 4, 3, 6, 7, -1, 3});
    cout << "Original Array :: ";
    s.Print();
    cout << "Bubble Sort    :: ";
    s.BubbleSort();
    s.Print();
    cout << "Insertion Sort :: ";
    s.InsertionSort();
    s.Print();
    cout << "Selection Sort :: ";
    s.SelectionSort();
    s.Print();

    return 0;
}