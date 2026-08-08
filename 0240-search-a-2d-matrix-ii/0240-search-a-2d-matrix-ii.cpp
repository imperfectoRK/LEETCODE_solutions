class Solution {
public:
int m,n;
    bool solver(vector<vector<int>> &mat, int t, int idx,int idy)
    {
        if(idx<0 || idy<0 || idx>=m || idy>=n) return 0;
        if(mat[idx][idy]==t) return true;

        if(mat[idx][idy]>t) return solver(mat,t,idx,idy-1);
        
        return solver(mat,t,idx+1,idy);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        m=matrix.size(), n=matrix[0].size();
        return solver(matrix,target,0,n-1);
    }
};