/*有四种情况：
L...L 中间的点都变为 L
R...R 中间的点都变为 R
L...R 中间的点不变
R...L 中间前一半的点变为 R，后半部分变为 L。如果正中间有点，则不变
为了方便实现，左边放一个 L 哨兵，右边放一个 R 哨兵*/

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int j = -1;
        for ( int i = 0; i <= n; i++ )
        {
            char cur = i == n ? 'R' : dominoes[i];
            if ( cur == '.' )
                continue;
            
            char pre = j == -1 ? 'L' : dominoes[j];
            if ( pre == 'L' && cur == 'L' )
                for ( int k = j + 1; k < i; k++ )
                    dominoes[k] = 'L';
                
            else if ( pre == 'R' && cur == 'R' )
                for ( int k = j + 1; k < i; k++ )
                    dominoes[k] = 'R';

            else if ( pre == 'R' && cur == 'L' )
            {
                // 这里边界举个例子就能试出来
                for ( int k = j + 1; k < (i + j + 1) / 2; k++ )
                    dominoes[k] = 'R';
                for ( int k = (i + j) / 2 + 1; k < i; k++ )
                    dominoes[k] = 'L';
            }
            j = i;
        }

        return dominoes;
    }
};
