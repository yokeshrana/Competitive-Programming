class Solution {
    public int lengthOfLongestSubstring(String st) {
        
        //Sliding window approach
        char mp[]=new char[128];
        int res=0;
        int s=0,e=0;
        
        while(e<st.length()){
            char c=st.charAt(e);
            mp[c]++;
            /*
            This is important step
            As soon as we see duplicate ,we start removing one one element from the start of the window
            and slide the window until we get the end index char removed from the left side.
            */
            while(mp[c]>1){             
                char l = st.charAt(s);
                mp[l]--;
                s++;
            }
            res=Math.max(res,e-s+1);
            e++; 
        }
        return res;
    }
}