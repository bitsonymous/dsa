class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, n = nums.size();
        vector<vector<int>> ans;
        while(i<n){
            if(i>0 and nums[i] == nums[i-1]){
                i++;
                continue;
            }
            int m = i + 1;
            int  j= n - 1;
            while(m<j){
                int sum = nums[i] + nums[m] + nums[j];
                if(sum == 0){
                    ans.push_back({nums[i], nums[m], nums[j]});
                    while(m<j and nums[m] == nums[m+1]){
                        m++;
                    }
                    while(m<j and nums[j] == nums[j-1]){
                        j--;
                    }
                    m++;
                    j--;
                }else if(sum < 0){
                    while(m<j and nums[m] == nums[m+1]){
                        m++;
                    }
                    m++;
                }else{
                    while(m<j and nums[j] == nums[j-1]){
                        j--;
                    }
                    j--;
                }
            }
            i++;
        }
        return ans;
    }
};