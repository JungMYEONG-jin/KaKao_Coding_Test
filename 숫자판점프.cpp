#include <iostream>

using namespace std;
    
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool visited[1000001];
int map[5][5];
int ans = 0;

void dfs(int x, int y, int sum, int cnt)
{
        if(5==cnt)
        {
            if(!visited[sum])
            {
                visited[sum] = true;
                ans++;
            }
            return;
        }

        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && ny>=0 && nx<5 && ny<5)
            {
                dfs(nx, ny, 10*sum+map[nx][ny], cnt+1);
            }
        }

}

int main()
{
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
                cin>>map[i][j];
        }

        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                dfs(i, j, map[i][j], 0);
            }
        }
        cout<<ans<<endl;
    }

