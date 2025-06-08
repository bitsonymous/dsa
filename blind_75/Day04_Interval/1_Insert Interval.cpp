class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intv, vector<int>& ni) {
        int n = intv.size();
        int idx = 0;
        vector<vector<int>> ans;
        while(idx < n and intv[idx][1] < ni[0]){ // find loc to insert
            ans.push_back(intv[idx]);
            idx++;
        }
        // if(idx<n and idx >= 0) cout<<intv[idx][1]<<" "<<ni[0]<<endl;
        while(idx < n and intv[idx][0] <= ni[1]){
            ni[0] = min(intv[idx][0], ni[0]);
            ni[1] = max(intv[idx][1], ni[1]);
            idx++;
        }

        ans.push_back(ni);

        for(int i = idx; i<n; i++){ // insert rest elements
            ans.push_back(intv[i]);
        }
        return ans;
    }
};