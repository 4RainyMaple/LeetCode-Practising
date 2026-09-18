class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        //直接定义数组方便控制大小，注意初始值是false
        bool row_exist [9][9];    //第i行存在元素x
        bool col_exist [9][9];    //第j列存在元素x
        bool sub_space_exist [3][3][9];     //  宫格i,j存在元素x

        for ( int i = 0; i < 9; ++i )   //行循环
        {
            for ( int j = 0; j < 9; ++j )
            {
                char ele = board[i][j];

                if ( ele == '.' )
                    continue;

                int x = ele - '1';  //把字符转换为小一的整数，匹配容器
            
                if ( row_exist[i][x] || col_exist[j][x] || sub_space_exist[i/3][j/3][x] )
                    return false;

                row_exist[i][x] = col_exist[j][x] = sub_space_exist[i/3][j/3][x] = true;
            }
        }

        return true;
    }
};
