class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int res = 0;
        unordered_map<int, int> rows;
        
        for (auto reserved : reservedSeats) {
            rows[reserved[0]] |= (1 << (reserved[1]-1));
        }

        for (auto [row, seats] : rows) {
            bool a = (~seats & 30) == 30;   
            bool b = (~seats & 120) == 120; 
            bool c = (~seats & 480) == 480; 
            
          
            res += (a && c) ? 2 : (a || c ) ? 1 : b;
        }
        
        
        res += 2 * (n - rows.size());
        
        return res;
    }
};