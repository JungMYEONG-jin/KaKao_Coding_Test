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

#define INF 999999999

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dp[61][61][61];
int hp[3] = {0,};

int getMinCount(int x, int y, int z){
    if (x<0)
    {
        return getMinCount(0, y, z);
    }
    if (y<0)
    {
        return getMinCount(x, 0, z);
    }
    if (z<0)
    {
        return getMinCount(x, y, 0);
    }
    
    if (x == 0 && y == 0 && z == 0)
    {
        return 0;
    }

    int& res = dp[x][y][z];
    if (res != -1)
    {
        return res;
    }
    res = INF;
    res = min(res, getMinCount(x-9, y-3, z-1)+1);
    res = min(res, getMinCount(x-9, y-1, z-3)+1);
    res = min(res, getMinCount(x-3, y-9, z-1)+1);
    res = min(res, getMinCount(x-3, y-1, z-9)+1);
    res = min(res, getMinCount(x-1, y-3, z-9)+1);
    res = min(res, getMinCount(x-1, y-9, z-3)+1);
    return res;
}

int main()
{
    // input
    ios_base::sync_with_stdio(0);
	cin.tie(0); 
    cout.tie(0);
    int n;
    cin>>n;
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n;i++)
        cin>>hp[i];
    cout<<getMinCount(hp[0], hp[1], hp[2]);
    return 0;
}
