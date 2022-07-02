Best thing is here how we are using string as stack for manipulations
```
string removeDuplicates(string s) {
string ans="";
for(auto &c:s){
if(ans.size()&&c==ans.back()) ans.pop_back();
else
ans.push_back(c);
}
return ans;
}
```