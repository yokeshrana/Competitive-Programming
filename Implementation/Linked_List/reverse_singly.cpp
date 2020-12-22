#include <bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    struct node *link;
};
struct node *insert(struct node *head, int val)
{
    struct node *tmp = new node;
    tmp->val = val;
    tmp->link = head;
    head = tmp;
    return head;
}
void print(struct node *head)
{
    struct node *tmp = head;
    while (tmp)
    {
        cout << tmp->val;
        tmp = tmp->link;
    }
    cout<<""<<endl;
}
struct node *reverse(struct node *head)
{
    struct node *curr = head, *next, *prev = nullptr;
    while (curr)
    {
        next=curr->link;
        curr->link = prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
int main()
{
    struct node *ll=nullptr;
    for (int i = 5; i > 0; i--)
        ll = insert(ll, i);
    print(ll);
    ll = reverse(ll);
    print(ll);
    return 0;
}