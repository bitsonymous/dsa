class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        vector<int> ans;
        int leftcol = 0, rightcol = m-1, toprow = 0, bottomrow = n-1;
        while(toprow <= bottomrow and leftcol <= rightcol){
            if(toprow <= bottomrow and leftcol <= rightcol){
                for(int left = leftcol; left<=rightcol; left++){
                    ans.push_back(matrix[toprow][left]);
                }
                toprow++;
            }
            if(toprow <= bottomrow and leftcol <= rightcol){
                for(int top = toprow; top <= bottomrow ; top++){
                    ans.push_back(matrix[top][rightcol]);
                }
                rightcol--;
            }
            if(toprow <= bottomrow and leftcol <= rightcol){
                for(int right = rightcol; right>= leftcol; right--){
                    ans.push_back(matrix[bottomrow][right]);
                }
                bottomrow--;
            }
            if(toprow <= bottomrow and leftcol <= rightcol){
                for(int bottom = bottomrow; bottom >= toprow; bottom--){
                    ans.push_back(matrix[bottom][leftcol]);
                }
                leftcol++;
            }
        }
        return ans;
    }
};