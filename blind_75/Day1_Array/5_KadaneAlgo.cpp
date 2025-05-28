class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = INT_MIN, curr = 0;

        for(auto it:  nums){
            curr += it;
            sum = max(curr, sum);
            if(curr<0) curr = 0;
        }
        return sum;
    }
};