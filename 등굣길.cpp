#include <string>
#include <vector>
#include <cstring>
#include <functional>

using namespace std;

long long mod = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    
    int dp[101][101];
    int dir_y[2]={0,1};
    int dir_x[2]={1,0};
    
    
    memset(dp, -1, sizeof(dp));
    
    for(auto& i : puddles)
        dp[i[0]][i[1]]=-2; // 물웅덩이
    
    
    function<int(int, int, int, int)> dfs = [&dfs, &dp, &dir_y, &dir_x](int x, int y, int m, int n){
        if(x==m && y==n)
            return 1;
        if(dp[x][y]==-1) // 아직 가지 않았다면
        {
            dp[x][y] =0;
            for(int i=0;i<2;i++)
            {
                int next_x = x+dir_x[i];
                int next_y = y+dir_y[i];
                
                if(next_x>0 && next_x<=m && next_y>=0 && next_y<=n)
                {
                    if(dp[next_x][next_y]==-2)
                        continue; //웅덩이
                   dp[x][y]+= dfs(next_x, next_y, m, n)%mod;                 
                }
                
            }
        }
        return dp[x][y];
    };
    
    
    
    
    
    dfs(1,1,m,n);
    
    return dp[1][1]%mod;
}
