#include<vector>
#include <set>
#include <queue>
#include <cstring>
using namespace std;
bool visited[101][101];
int solution(vector<vector<int>> maps)
{
    int answer = -1;



    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};

    int n = maps.size();
    int m = maps[0].size();

    queue<pair<pair<int, int>, int>> res;
    visited[0][0] = true;

    res.push({{0,0},1});

    while(!res.empty())
    {
        auto k = res.front();
        res.pop();


        int x = k.first.first;
        int y = k.first.second;
        int step = k.second;

        if(x==n-1 && y==m-1) return step;


        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            /*
            if(nx<0 || ny<0 || nx>=n || ny>=m)
                continue;

            if(visited[nx][ny])
                continue;
            if(maps[nx][ny]!=1)
                continue;
            */
            if(nx>=0 && ny>=0 && nx<n &&ny<m)
            {
                if(!visited[nx][ny] && maps[nx][ny]==1)
                {
                    res.push({{nx, ny}, step+1});
                    visited[nx][ny]=true;
                }
            }



        }




    }

    return -1;
}
