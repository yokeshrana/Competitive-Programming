class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string,vector<string>> adj;  
        map<string,int> indegree; 
        
        for(int i=0;i<ingredients.size();i++){  
            
            for(int j=0;j<ingredients[i].size();j++){
                
                adj[ingredients[i][j]].push_back(recipes[i]);
                indegree[recipes[i]]++;        
            }
        }
        
        queue<string> q;
        vector<string> ans;
        
        for(int i=0;i<supplies.size();i++) q.push(supplies[i]); 
        
        while(!q.empty()){   
            string node = q.front();
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                    ans.push_back(it);      
            }
            }
        }
        
        return ans;
            }
};