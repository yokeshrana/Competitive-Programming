#include <bits/stdc++.h>
using namespace std;
#define SIZE 10
class Mystack
{
    public:
    void push(char item)
    {   
        if (top == SIZE - 1)
        {
            printf("-> Stack Overflow\n");
         
        }
        else
        {
            size[++top] = item;
           
        }
    }
    void pop()
    {
        if (top == -1)
        {
            printf("-> Stack UnderFlow\n");
        }
        else
        {
            top--;
        }
    }
    bool empty(){
        if(top==-1)return true;else return false;
    }

    void print(){
        for(auto x:size){
            cout<<x<<" ";
            cout<<endl;
        }
    }
    char peek(){
        return size[top];
    }

private:
    char size[SIZE];
    int top=-1;
};

bool checkBalance(string s){
    Mystack st;
for(auto x:s){
    cout<<"Processing "<<x<<" :\n";
    if(x=='{'||x=='['){
        st.push(x);
    }else
    {
        if(st.peek()=='['&&x==']'||st.peek()=='{'&&x=='}')
            st.pop();
        else
            return false;
    }
}
cout<<"Is balanced :: ";
return st.empty();
}

string infix_to_postfix(string s){
    Mystack st;
    for(auto x:s){
        if(!(x=='+'||x=='-'||x=='*'||x=='/'))
            cout<<x;
            else
            {
                st.push(x);
            }
    }
    string news="";
    while(!st.empty()){
       news=news+st.peek();
       st.pop();
    }
    return news;
}

int main()
{
    string s="1+3-5*4";
    
    cout<<infix_to_postfix(s)<<endl;  
    return 0;
}
