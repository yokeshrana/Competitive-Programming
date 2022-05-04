class Solution {
public:
    
    bool check(vector<vector<int>> &image,int sr,int sc,int prev){
        if(sr>=0&&sc>=0&&sr<image.size()&&sc<image[0].size()&&image[sr][sc] == prev)
        return true;
        else
        return false;
        }
    
 void fill(vector<vector<int>>& image, int sr, int sc,int prevColor,int newColor)
     {
        
       if(check(image,sr,sc-1,prevColor))
       {
           image[sr][sc-1]=newColor;
            fill(image,sr,sc-1,prevColor,newColor);
       }
         if(check(image,sr+1,sc,prevColor))
       {
           image[sr+1][sc]=newColor;
              fill(image,sr+1,sc,prevColor,newColor);
       }
         if(check(image,sr,sc+1,prevColor))
       {
           image[sr][sc+1]=newColor;
              fill(image,sr,sc+1,prevColor,newColor);
       }
         if(check(image,sr-1,sc,prevColor))
       {
           image[sr-1][sc]=newColor;
              fill(image,sr-1,sc,prevColor,newColor);
       }
         
     }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int prev=image[sr][sc];
        if(prev == newColor)
            return image;
        image[sr][sc]=newColor;
        fill(image,sr,sc,prev,newColor);
    return image;
    }
};