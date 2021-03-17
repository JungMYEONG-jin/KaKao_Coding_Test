#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    bool flag =false;

    while(!flag)
    {

    flag =true;   
    vector<vector<bool>> res(m, vector<bool>(n));
    for(int i=0;i<m-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(board[i][j]!=0)
            {
                if(board[i][j]==board[i+1][j] && board[i][j]==board[i][j+1] && board[i][j]==board[i+1][j+1]){

                    res[i][j]=true;
                    res[i+1][j]=true;
                    res[i][j+1]=true;
                    res[i+1][j+1]=true;
                    flag=false;
                }
            }
        }
    }

    if(!flag)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(res[i][j])
                {
                    answer++;
                    for(int k=i-1;k>=0;k--)
                    {
                        swap(board[k+1][j], board[k][j]);
                        board[k][j]=0;
                    }
                }


            }
        }
    }



    }




    return answer;
}
