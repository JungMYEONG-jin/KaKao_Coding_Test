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

int main()
{
    // input
    ios_base::sync_with_stdio(0);
	cin.tie(0); 
    cout.tie(0);
    int n, m;
    int dp[1001][1001];
    memset(dp, 0, sizeof(dp));

    cin>>n>>m;
    vector<vector<int>> arr(n+1, vector<int>(m+1, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = max(dp[i-1 < 0 ? 0 : i-1][j], max(dp[i][j-1 < 0 ? 0 : j-1], dp[i-1 < 0 ? 0 : i-1][j-1 < 0 ? 0 : j-1])) + arr[i][j];
        }
    }

    cout<<dp[n][m]<<endl;

    return 0;
}
