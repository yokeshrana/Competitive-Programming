#include <bits/stdc++.h>
using namespace std;
struct heap
{
    int *array;
    int count;
    int capacity;
    int type; //1 for max and 0 for min
};
struct heap *createheap(int capacity)
{
    struct heap *myheap = (struct heap *)malloc(sizeof(struct heap));
    myheap->capacity = capacity;
    myheap->array = (int *)malloc(sizeof(int) * capacity);
    myheap->count = 0;
    return myheap;
}
int parentOf(struct heap *h, int i)
{
    if (i > h->capacity || i <= 0)
        return -1;
    return h->array[(i - 1) / 2];
}
int leftChild(struct heap *h, int i)
{
    return h->array[2 * i + 1];
}
int rightChild(struct heap *h, int i)
{
    return h->array[2 * i + 2];
}
int getMaxorMin(struct heap *h)
{ //Since max is always at root
    return h->array[0];
}

// insert at end ,if property violate then swap with parent recursively //same happens if we modify some
//element of heap
void insert(struct heap *h, int data)
{
    int index = h->count++;

    while (index >= 0 && data > parentOf(h, index))
    {
        if (parentOf(h, index) == -1)
            break;
        swap(h->array[index], h->array[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
    h->array[index] = data;
}
//Needed as when we insert the element in the heap it breaks the heap property
//Find the maximum of its children and swap with that
void heapify(struct heap *h, int i)
{
    int left = 2 * i + 1 <= h->count ? 2 * i + 1 : i;
    int right = 2 * i + 2 <= h->count ? 2 * i + 2 : i;
    int max = i;
    if (h->array[left] > h->array[max])
        max = left;
    if (h->array[right] > h->array[max])
        max = right;
    if (max != i)
    {
        swap(h->array[max], h->array[i]);
        heapify(h, max);
    }
}
int removeMinmax(struct heap *h) //Or Delete an element from heap
{
    int element = h->array[0];
    swap(h->array[0], h->array[h->count - 1]); //swap last node with min /max element
    h->count--;                                //decreasing heap by 1 element
    heapify(h, 0);                             //call heapify on root node;
    return element;
}
void buildheap(struct heap *h, vector<int> arr)
{
    h->count = arr.size();
    for (int i = 0; i < h->count; i++)
    {
        h->array[i] = arr[i];
    }
    for (int i = arr.size() / 2; i >= 0; i--)
        heapify(h, i);
}
int main()
{

    struct heap *myheap = createheap(20);
    insert(myheap, 10);
    insert(myheap, 30);
    insert(myheap, 20);
    insert(myheap, 390);
    insert(myheap, 130);
    insert(myheap, 310);
    insert(myheap, 0);
    insert(myheap, 360);
    //cout << getMaxorMin(myheap) << endl; //390
    //When we extract Max or  Min ,Then we have to reheapify the entire tree  ie move from top of the
    // tree to bottom and correct the property
    cout << removeMinmax(myheap) << endl;
    cout << removeMinmax(myheap) << endl;
    cout << removeMinmax(myheap) << endl;
    cout << removeMinmax(myheap) << endl;
    cout << removeMinmax(myheap) << endl;
    cout << removeMinmax(myheap) << endl;
    cout << removeMinmax(myheap) << endl;
    cout << removeMinmax(myheap) << endl;
    //For single element insertion its okay to use insert method ,but if we want to build heap from array
    //then we use the build heap method
    //Since leaf nodes always satisfy heap property they are not needed to include for heapify operation
    // so we do heapfiy only on non leaf node
    //see Buildheap function for more clarity
    buildheap(myheap, {11, 2, 33, 51, 6, 78, 1000, 36});
    cout << getMaxorMin(myheap) << endl; //1000
    return 0;
}