class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long N = n*n;
        long long e_sum = N*(N+1)/2, e_sqr_sum = N*(N+1)*(2*N+1)/6, sum = 0, sqr_sum = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                sum += grid[i][j];
                sqr_sum += grid[i][j]*grid[i][j];
            }
        }
        int diff1 = e_sum - sum; // missing - duplicate 
        int diff2 = e_sqr_sum - sqr_sum; //missing^2 - duplicate^2;

        int eq1 = diff1;
        int eq2 = diff2 / diff1;

        int missing = (eq1+eq2)/2;
        int duplicate = missing - diff1;

        return  {duplicate, missing};

    }
};