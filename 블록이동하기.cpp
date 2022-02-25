#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <iostream>

using namespace std;

int ans = 0;
set<tuple<int, int, int, int>> visited;
queue<tuple<int, int, int, int>> q;
vector<vector<int>> tempBoard;
int len;

bool push(int x, int y, int x2, int y2)
{
    auto it = make_tuple(x, y, x2, y2);
    if(visited.find(it)!=visited.end()) // exist
    {
        return false;
    }
    visited.insert(it);
    q.push(it);
    return true;
}

void bfs()
{
    int dir[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    int rotate[2] = {1, -1};
    
    while(!q.empty())
    {
        int sz = q.size();
        for(int d=0;d<sz;d++)
        {
            auto it = q.front();
            q.pop();
            int x, y, x2, y2;
            tie(x, y, x2, y2) = it;
            if((x==len-1 && y==len-1) || (x2==len-1 && y2==len-1))
                return;
            
            for(int i=0;i<4;i++)
            {
                int nx = x+dir[i][0];
                int ny = y+dir[i][1];
                int nx2 = x2+dir[i][0];
                int ny2 = y2+dir[i][1];
                
                if(nx<0 || ny<0 || nx2<0 || ny2<0 || nx>=len || ny>=len || nx2>=len || ny2>=len)
                        continue;
                if(tempBoard[nx][ny]==0 && tempBoard[nx2][ny2]==0)
                    push(nx, ny, nx2, ny2);
            }
            
            if(x==x2)
            {
                for(int r : rotate)
                {
                    int nx = x+r;
                    int ny = y;
                    int nx2 = x2+r;
                    int ny2 = y2;
                    
                    if(nx<0 || ny<0 || nx2<0 || ny2<0 || nx>=len || ny>=len || nx2>=len || ny2>=len)
                        continue;
                    if(tempBoard[nx][ny]==0 && tempBoard[nx2][ny2]==0)
                    {
                        push(x,y,nx,ny);
                        push(x2,y2,nx2,ny2);
                    }
                    
                }
            }
            
            if(y==y2)
            {
                for(int r : rotate)
                {
                    int nx = x;
                    int ny = y+r;
                    int nx2 = x2;
                    int ny2 = y2+r;
                    
                    if(nx<0 || ny<0 || nx2<0 || ny2<0 || nx>=len || ny>=len || nx2>=len || ny2>=len)
                        continue;
                    if(tempBoard[nx][ny]==0 && tempBoard[nx2][ny2]==0)
                    {
                        push(x,y,nx,ny);
                        push(x2,y2,nx2,ny2);
                    }
                    
                }
            }
            
            
        }
        ans++;
    }
    
    
    
    
    
}



int solution(vector<vector<int>> board) {
    int answer = 0;
    len = board.size();
    tempBoard = board;
    push(0, 0, 0, 1);
    bfs();
    answer = ans;
    return answer;
}
