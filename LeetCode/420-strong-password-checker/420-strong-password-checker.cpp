class Solution {
public:
    int strongPasswordChecker(string s) {
        int n=s.length(),ans=0;
        int same[n]; memset(same,0,sizeof(same));
        bool dig=1,sml=1,cap=1;
        
        for(int i=0;i<n;)
        {
            if('a'<=s[i] && s[i]<='z') sml=0;
            else if('A'<=s[i] && s[i]<='Z') cap=0;
            else if('0'<=s[i] && s[i]<='9') dig=0;
            
            int j=i;
            while(i<n && s[i]==s[j]) same[j]++,i++;
        }
        
        int miss=dig+sml+cap;
        if(n<6) ans=(miss+max(0,6-(n+miss)));
        else
        {
            int over=max(0,n-20),left=0;
            ans+=over;
            
            for(int i=1;i<3;i++)
                for(int j=0;j<n && over>0;j++)
                {
                    if(same[j]<3 || same[j]%3!=(i-1)) continue;
                    same[j]-=min(over,i);
                    over-=i;
                }
            
            for(int i=0;i<n;i++)
            {
                if(same[i]>=3 && over>0)
                {
                    int need=same[i]-1;
                    same[i]-=over;
                    over-=need;
                }
                if(same[i]>=3) left+=same[i]/3;
            }
            
            ans+=max(miss,left);
        }
        
        return ans;
    }
};