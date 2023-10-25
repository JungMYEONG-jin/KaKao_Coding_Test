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

int attck[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 9, 3},
    {1, 3, 9}
};

int main()
{
    // input
    ios_base::sync_with_stdio(0);
	cin.tie(0); 
    cout.tie(0);
    int n;
    cin>>n;
    
    int arr[3] = {0, 0, 0};

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    

    int res[arr[0]+1][arr[1]+1][arr[2]+1];
    memset(res, 0, sizeof(res));
    res[arr[0]][arr[1]][arr[2]] = 0;

    queue<tuple<int, int, int>> q;
    q.push({arr[0], arr[1], arr[2]});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int x, y, z;
        tie(x, y, z) = it;
        if (x ==0 && y ==0 && z==0)
        {
            break;
        }
        for(int i=0;i<6;i++){
            int nx = (x - attck[i][0]) > 0 ? x - attck[i][0] : 0;
            int ny = (y - attck[i][1]) > 0 ? y - attck[i][1] : 0;
            int nz = (z - attck[i][2]) > 0 ? z - attck[i][2] : 0;

            if (res[nx][ny][nz] == 0)
            {
                q.push({nx, ny, nz});
                res[nx][ny][nz] = res[x][y][z] + 1;
            }
        }
    }

    cout<<res[0][0][0];

    return 0;
}
