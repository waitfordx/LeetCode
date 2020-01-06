// 用约束编程和回溯法解数独
#include <vector>
#include <iostream>

using namespace std;

class Solution{

private:
// 数独的大小是固定的， 9个盒子， 每个盒子 3*3 
static const int n = 3;
static const int N = n * n;
// 定义3个二维数组，用来约束每个位置可以填入的数字

int rows[N][N+1];           // 记录每行可以放置的数字 1-9
int columns[N][N+1];        // 记录每列可以放置的数字 1-9
int boxes[N][N+1];          // 记录每个盒子可以放置的数字 1-9

vector<vector<char>> board;

bool solved = false;        // 表示数独是否已经被解决

public:
// 判断在 row， col 这个位置是否可以放置 d 这个数字
bool CouldPlace(int d, int row, int col)
{
    int idx = (row/n)*n + col/n;                                    // 表示在第几个盒子， 盒子编号0-8
    return rows[row][d] + columns[col][d] + boxes[idx][d] == 0;     // 0 表示该位置无数字
}

// 将数组 d 放置到 row col 这个位置
void placeNumber(int d, int row, int col)
{
    int idx = (row/n)*n + col/n;
    rows[row][d]++;
    columns[col][d]++;
    boxes[idx][d]++;                                                // 各位置置为1，表示已有数据填充

    board[row][col] = (char)(d+'0');
}

// 从 row col 位置移除一个不能求解的数字
void removeNumber(int d, int row, int col)
{
    int idx = (row/n)*n + col/n;
    rows[row][d]--;
    columns[col][d]--;
    boxes[idx][d]--;

    board[row][col] = '.';
}

// 填充 row col 的下一个位置，以行为顺序, 调用回溯函数 backtrack（）
void placeNextNumber(int row, int col)
{
    if((col == N-1) && (row == N-1)) solved = true;
    else
    {
        if(col == N-1)
        {
            backtrack(row + 1, 0);
        }
        else
        {
            backtrack(row, col+1);
        }
    }
}

// 回溯函数，不断尝试每个位置可以放置的值
void backtrack(int row, int col)
{
    if(board[row][col] == '.')
    {
        for(int i = 1; i < 10; i++)
        {
            if(CouldPlace(i, row, col))
            {
                placeNumber(i, row, col);
                // 填充一下一个位置， 调用了 backtrack（）函数，递归调用
                placeNextNumber(row, col);
                // 如果未得到正确解， 需要回溯一步删除填入的数字，尝试下一个数字
                if(!solved) removeNumber(i, row, col);
            }
        }
    }
    else
    {
        placeNextNumber(row, col);
    }
}

void solveSudoku(vector<vector<char>>& board)
{
    this->board = board;
    // 初始化约束数组
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            char num = board[i][j];
            if(num != '.')
            {
                int d = (int)(num - '0');
                placeNumber(d, i, j);
            }
        }
    // 开始回溯求解
    backtrack(0, 0);
    // 改变的是 this->board.
    board = this->borad;
}

};// end of class Solution