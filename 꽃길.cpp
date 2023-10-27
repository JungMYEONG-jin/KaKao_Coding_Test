#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <random>
#include <numeric>
#include <cstring>

#define INF 999999999

using namespace std;


int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool visited[10][10];
int arr[10][10];
int ans = 999999999;
int n;

void reset(int i, int j){
    visited[i][j] = false;
    for(int d=0;d<4;d++){
        int nx = i+dx[d];
        int ny = j+dy[d];
        visited[nx][ny] = false;
    }
}

int getFlowerSum(int x, int y){
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (visited[nx][ny])
        {
            return -1;
        }
    }

    int total = arr[x][y];
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        visited[nx][ny] = true;
        total+=arr[nx][ny];
    }
    return total;
}

void dfs(int x, int y, int cnt, int cost){
    if (cnt == 3)
    {
        ans = min(cost, ans);
        return;
    }

    //do
    for(int i=x;i<n-1;i++){
        for(int j=1;j<n-1;j++){
            if (visited[i][j])
            {
                continue;
            }
            int sum = getFlowerSum(i, j);
            // find next
            if (sum != -1)
            {
                dfs(i, j, cnt+1, cost+sum);
                reset(i, j);
            }
            
            
        }
    }
    
}


int main()
{
    // input
    ios_base::sync_with_stdio(0);
	cin.tie(0); 
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    memset(visited, false, sizeof(visited));

    for(int i=1;i<n-1;i++){
        for(int j=1;j<n-1;j++){
            int sum = getFlowerSum(i, j);
            dfs(i, j, 1, sum);
            reset(i, j);
        }
    }

    cout<<ans<<endl;

    return 0;
}
