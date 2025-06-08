class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intv) {
        vector<vector<int>> ans;
        sort(intv.begin(), intv.end());
        ans.push_back(intv[0]);
        int n = intv.size();
        for(int i = 1; i<n; i++){
            if(ans.back()[1] >= intv[i][0]){
                ans.back()[1] = max(intv[i][1], ans.back()[1]); 
            }else{
                ans.push_back(intv[i]);
            }
        }
        return ans;
    }
};