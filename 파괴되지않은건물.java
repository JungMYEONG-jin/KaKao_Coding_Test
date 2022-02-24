class Solution {
    public int solution(int[][] board, int[][] skill) {
        int answer = 0;

        int row = board.length;
        int col = board[0].length;
        int irow = row+1;
        int icol = col+1;
        int[][] imos = new int[irow][icol];

        for(int[] info : skill)
        {
            int type = info[0];
            int r1 = info[1];
            int c1 = info[2];
            int r2 = info[3]+1;
            int c2 = info[4]+1;
            int degree = info[5];

            if(type==1)
            {
                imos[r1][c1]-=degree;
                imos[r2][c2]-=degree;
                imos[r1][c2]+=degree;
                imos[r2][c1]+=degree;
            }else if(type==2)
            {
                imos[r1][c1]+=degree;
                imos[r2][c2]+=degree;
                imos[r1][c2]-=degree;
                imos[r2][c1]-=degree;
            }

        }
        
        for(int i=0;i<irow;i++)
        {
            int now = 0;
            for(int j=0;j<icol;j++)
            {
                now+=imos[i][j];
                imos[i][j] = now;
            }
        }
        
        for(int i=0;i<icol;i++)
        {
            int now = 0;
            for(int j=0;j<irow;j++)
            {
                now+=imos[j][i];
                imos[j][i] = now;
            }
        }
        
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                board[i][j]+=imos[i][j];
                if(board[i][j]>0)
                    answer++;
            }
        }

        return answer;
    }
}
