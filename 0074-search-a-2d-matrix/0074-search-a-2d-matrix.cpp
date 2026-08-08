class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        //first i have to find the first place just lower than the target
        int m=matrix.size(),n=matrix[0].size();
        int left=0,right=m*n-1;

        while(left<=right)
        {   
            int mid=(left+right)>>1;
            int i=mid/n, j=mid%n;
            if (matrix[i][j] == target)
                return true;
            if(matrix[i][j]<target)
            {
              left=mid+1;
            }
            else right=mid-1;
        }
        return false;
    }
};