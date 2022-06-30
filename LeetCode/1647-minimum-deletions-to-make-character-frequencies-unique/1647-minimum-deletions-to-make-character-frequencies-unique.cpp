class Solution {
public:
    int minDeletions(string s) {
   
   vector<int> freq(26,0);
    for(auto &v:s){
        freq[v-'a']++;
    }
    
    priority_queue<int> pq;
    for(auto x:freq){if(x>0) pq.push(x);}
    
    int count=0;
        while(pq.size()>1){
            int top=pq.top();
            pq.pop();
            if(top==pq.top()){
                //making sure that we dont push any negative val
                if(top-1>0)
                pq.push(top-1);
                count++;
            }
        }
       
       return count;
        
    }
};