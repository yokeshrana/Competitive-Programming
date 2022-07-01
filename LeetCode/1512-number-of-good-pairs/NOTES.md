Note for each of the element there will be mp[element] pairs .
​
```
class Solution {
public:
int numIdenticalPairs(vector<int>& nums) {
int c=0;
map<int,int> mp;
for(auto x:nums){
c+=mp[x]++;
}
return c;
}
};
```