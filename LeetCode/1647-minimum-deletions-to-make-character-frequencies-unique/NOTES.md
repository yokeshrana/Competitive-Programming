First approach is to have a map of char and frequency
and then iterate over map and keep on decreasing frequency until we make it unique .
while deleting if frequency becomes zero discard that element.
```
int minDeletions(string s) {
map<char,int> mp;
int count=0;
for(char c:s)
mp[c]++;
set<int> seen;
for(auto it=mp.begin();it!=mp.end();it++){
while(seen.find(it->second)!=seen.end())
{
(it->second)--;
count++;
}
if(it->second>0)
seen.insert(it->second);
}
return count;
}
```
​
​