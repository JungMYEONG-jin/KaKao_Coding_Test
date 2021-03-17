#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;

    int row = board.size();
    int col = board[0].size();

    int sq[1001][1001];

    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            sq[i+1][j+1]=board[i][j];

    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            if(sq[i][j]!=0)
            {
            sq[i][j] = min(min(sq[i-1][j], sq[i][j-1]),sq[i-1][j-1])+1;
            answer = max(answer, sq[i][j]);
            }
        }
    }


    return answer*answer;
}
