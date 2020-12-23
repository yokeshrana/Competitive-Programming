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
            cout<<"-> Pushed "<<(size[++top] = item)<<endl;
           
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
            cout<<"-> Popped "<<size[top]<<endl;
            size[--top];
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

int main()
{
    string s="[]][[]";
    cout<<checkBalance(s)<<endl;  
    return 0;
}
