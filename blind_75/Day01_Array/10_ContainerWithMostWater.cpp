class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0, e = height.size()-1, ans = 0;
        while(s<e){
            int l = e - s;
            int h = min(height[e], height[s]);
            ans = max(ans , l*h);
            if(height[s] < height[e]) s++;
            else e--;
        }
        return ans;
    }
};