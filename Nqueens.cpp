/* LeetCode 50  N皇后问题： 如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
** 即任意2个皇后不能在同行。同一列、同一条斜线上
** 经典的回溯问题
*/

class Solution{
public:
    // 判断 row， col 位置上是否可以放置 皇后 Q
    bool canplace(int row, int col)
    {
        int res = rows[col] + hills[row - col + 2*n] + dales[row+col];
        return (res == 0) ? true : false;
    }
    // 放置一个皇后到 row， col 位置上
    void  placeQueen(int row, int col)
    {
        queens[row] = col;
        rows[col] = 1;
        hills[row - col + 2*n] = 1;
        dales[row+col] = 1;
    }
    // （不能求得解）删除 row col 位置的皇后(恢复现场)
    void removeQueen(int row, int col)
    {
        queens[row] = 0;
        rows[col] = 0;
        hills[row - col + 2*n] = 0;
        dales[row+col] = 0;        
    }
    // 添加一个解到解集合中
    void addResult()
    {
        vector<string> result;
        for(int i = 0; i < n; i++)
        {
            int col = queens[i];
            string s = (n, '.');
            s.replace(i, 1, 1, 'Q');
            result.push_back(s);
        }
        res.push_back(result);
    }
    // 回溯函数
    void backtrack(int row)
    {
        for(int col = 0; col < n; col++)
        {
            if(canplace(row, col))
            {
                placeQueen(row, col);
                if(row + 1 ==  n) addResult();
                else backtrack(row+1);
                // 回溯
                removeQueen(row, col);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        // 初始化
        this->n = n;
        rows.resize(n, 0);
        dales.resize(2*n-1, 0);
        hills.resize(4*n-1, 0);
        queens.resize(n, 0);

        backtrack(0);
        return res;
    }


private:
    int n;
    // 按列循环
    vector<int> rows;
    // 主对角线
    vector<int> dales;
    // 次对角线
    vector<int> hills;
    // 记录皇后位置
    vecctor<int> queens;
    vector<vector<string>> res; 
};