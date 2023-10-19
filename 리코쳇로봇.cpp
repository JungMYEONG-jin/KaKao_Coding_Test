#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int solution(vector<string> board) {
    int answer = 9999999;
    int fx = board.size();
    int fy = board[0].size();
    int sx, sy = 0;
    int ex, ey = 0;

    for(int i=0, len = fx; i<len; i++){
        for(int j=0, blen =fy;j<blen;j++){
            if (board[i][j]=='R')
            {
                sx = i;
                sy = j;
            }else if(board[i][j]=='G'){
                ex = i;
                ey = j;
            }

        }
    }
    vector<vector<bool>> visited(fx, vector<bool>(fy, false));
    vector<vector<int>> dp(fx, vector<int>(fy, 9999999));

    queue<pair<int, int>> q;
    q.push({sx, sy});
    dp[sx][sy] = 0;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int x = it.first;
        int y = it.second;
        visited[x][y] = true;
        if (x==ex && y==ey)
        {
            answer = min(answer, dp[x][y]);
        }
        for(int i=0;i<4;i++){
            int nx = x;
            int ny = y;

            while(true){
                nx += dx[i];
                ny += dy[i];

                if(nx<0 || nx == fx || ny<0 || ny==fy){
                    nx -= dx[i];
                    ny -= dy[i];
                    break;
                }

                if(board[nx][ny] == 'D'){
                    nx -= dx[i];
                    ny -= dy[i];
                    break;
                }

            }

            if (visited[nx][ny])
            {
                continue;
            }


            q.push({nx, ny});
            dp[nx][ny] = min(dp[x][y] + 1, dp[nx][ny]);
        }
    }

    return answer == 9999999 ? -1 : answer;
}
