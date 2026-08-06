class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    vector<int> col,diag1,diag2;
    void solver(int row,int n)
    {
        if(row==n) { ans.push_back(board); return;}
        for(int c=0;c<n;c++)
        {
            if(col[c] || diag1[row-c+n-1] || diag2[row+c]) continue;

            board[row][c]='Q';
            col[c]=diag1[row-c+n-1]=diag2[row+c]=1;
            solver(row+1,n);
            
            board[row][c]='.';
            col[c]=diag1[row-c+n-1]=diag2[row+c]=0;
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        
        board.assign(n,string(n,'.'));
        col.assign(n,0);
        diag1.assign(2*n-1,0);
        diag2.assign(2*n-1,0);
        solver(0,n);
        return ans;
    }
};