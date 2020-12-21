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

struct node *nthfromend(struct node *head,int n){
    struct node *slow=head,*fast=head; 
    for(int i=0;i<n;i++){
        if(!fast)return nullptr;
        fast=fast->next;
    }
    while(fast->next){
       fast =fast->next;
       slow= slow->next;
    }
    return slow;
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

    cout<<nthfromend(root,3)->val<<endl;
    return 0;
}