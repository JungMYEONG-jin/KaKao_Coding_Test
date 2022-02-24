#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>


using namespace std;
bool visited[26][26][4];
vector<vector<int>> maps;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int len;
int minCost = 999999;

void bfs(int x, int y, int dir, int cost)
{
    queue<tuple<int, int, int, int>> q;
    q.push({x, y, dir, cost});
    visited[x][y][0] = visited[x][y][1] = visited[x][y][2] = visited[x][y][3] = true;
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        int px = get<0>(it);
        int py = get<1>(it);
        int pDir = get<2>(it);
        int pCost = get<3>(it);
        
        if(px==len-1 && py==len-1)
        {
            minCost = min(minCost, pCost);
        }
        
        for(int i=0;i<4;i++)
        {
            int nx = px+dx[i];
            int ny = py+dy[i];
            int nDir = i;
            int nCost = pCost;
            
            if(nx<0 || nx>=len || ny<0 || ny>=len || maps[nx][ny]==1)
                continue;
            
            if(pDir==-1)
                nCost+=100;
            else if(pDir==nDir)
                nCost+=100;
            else
                nCost+=600;
            
            if(!visited[nx][ny][nDir] || maps[nx][ny]>=nCost)
            {
                maps[nx][ny] = nCost;
                visited[nx][ny][nDir] = true;
                q.push({nx, ny, nDir, nCost});
            }
        }
    }
}


int solution(vector<vector<int>> board) {
    int answer = 0;
    maps = board;
    len = board.size();
    bfs(0, 0, -1, 0);
    answer = minCost;
    
    return answer;
}
