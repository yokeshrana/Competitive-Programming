#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    struct node *next;
    node(){
        val=0;
        next=nullptr;
    }
};
bool detectCycle(struct node* head){
    struct node *slow=head,*fast=head;
    if(!head) return false;
    while(slow&&fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)return true;
    }
    return false;
}

int main (){
    struct node* root;
    struct node* curr=root;
    for(int i=0;i<10;i++)
    {
        struct node *tmp=new node;
        tmp->val=i+1;
        curr->next=tmp;
        curr=curr->next;
    }
    curr->next=root;

    cout<<detectCycle(root)<<endl;
    return 0;
}