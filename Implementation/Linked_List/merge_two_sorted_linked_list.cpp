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
        cout << tmp->val<<" ";
        tmp = tmp->link;
    }
    cout<<endl;
}
struct node *reverse(struct node *head)
{
    struct node *curr = head, *next, *prev = nullptr;
    while (curr)
    {
        next=curr->link;
        curr->link = prev; //Imp Step we have to do ,rest all adjustment of links
        prev=curr;
        curr=next;
    }
    return prev;
}

struct node *reverse_recursive(struct node *head){
    if(!head)return nullptr; 
    if(!head->link) return head;//If single element return that 
    struct node *next=head->link; //Store next element 
    head->link=nullptr; //Break the node 
    //Now call the same funstion on another part of the list 
    struct node *reverse_rest=reverse_recursive(next); 
    //Now join back the list 
    next->link=head;

    return reverse_rest;
    
}
struct node *merge_them(struct node *a,struct node* b){
    if(!a)return b;
    if(!b) return a;
    struct node *tmp;
    if(a->val<b->val){
       a->link=merge_them(a->link,b); //Since a is smaller so we are adding in the list that we are preparing a to it  and making it link point to next recursice merging
       return a;
    }
    else
    {
       b->link=merge_them(a,b->link);//Since b is smaller so we are adding in the list that we are preparing b to it and making it link point to next recursice merging
       return b;
    }
    
}
int main()
{
    struct node *ll=nullptr;
    for (int i = 5; i > 0; i--)
        ll = insert(ll, i);
    print(ll);
    struct node *lp=nullptr;
    for (int i = 10; i > 5; i--)
    lp = insert(lp, i);
    print(lp);
    print(merge_them(ll,lp));

    return 0;
}
// 1 2 3 4 5 
// 6 7 8 9 10 
// 1 2 3 4 5 6 7 8 9 10 