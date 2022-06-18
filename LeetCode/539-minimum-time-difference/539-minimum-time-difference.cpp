class Solution {
public:
    
    int calDiff(string a,string b){
          int h1=stoi(a.substr(0,2));
          int m1=stoi(a.substr(3,2));
          int h2=stoi(b.substr(0,2));
          int m2=stoi(b.substr(3,2));
        return (h2-h1)*60+m2-m1;
        
    }
    
    int findMinDifference(vector<string>& timePoints) {
     sort(timePoints.begin(),timePoints.end());
     
     int minDiff=INT_MAX;
     for(int i=1;i<timePoints.size();i++)
     {
         minDiff=min({minDiff,
                      abs(calDiff(timePoints[i],timePoints[i-1])),
                     });
         
         //corner case
         minDiff=min(minDiff,abs(calDiff(timePoints[0],timePoints[timePoints.size()-1])-1440));
     }
        
     return minDiff;   
    }
};