#include <stdc++.h>
using namespace std;

struct trie {
    struct trie *child[26];
    int count; //count indicated no of word ending at this point.
    trie(){
        memset(child,0,26);
        count=0;
    }
};

struct trie *root;

void trie_insert(string s){
    struct trie *curr=root;
    for(char c:s){
        if(curr->child[c-'a']==0)
            curr->child[c-'a']=new trie;
        curr=curr->child[c-'a'];
        curr->count=0;
    }
    curr->count=1;
}
bool trie_search(string s){
    struct trie *curr=root;
    for(char c:s)
        if(curr->child[c-'a'])
             curr=curr->child[c-'a'];
        else 
            return false;

    return curr->count>0?true:false;
}



int main (){
    root=new trie;
    string arr[]={"fd","dfsfd","fsdfdsfsdgsh","df","et"};
    for(string x:arr)
        trie_insert(x);
    
    cout<<trie_search("df");


    cout<<endl;
    return 0;
}