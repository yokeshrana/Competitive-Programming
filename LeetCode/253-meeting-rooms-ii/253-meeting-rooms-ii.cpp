class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
           return a[0]<b[0]; 
        });
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        pq.push(INT32_MAX);
        
        for(auto &meeting:intervals){
            if(meeting[0] >= pq.top())
                pq.pop();
            pq.push(meeting[1]);
        }
        return pq.size()-1;
    }
};