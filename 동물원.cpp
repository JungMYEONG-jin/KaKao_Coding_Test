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

int dp[100001][3];

int main()
{
    // input
    ios_base::sync_with_stdio(0);
	cin.tie(0); 
    cout.tie(0);
    int n;
    cin>>n;
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;

    for(int i=2;i<=n;i++){
        dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % 9901;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 9901;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % 9901;
    }

    cout<< (dp[n][0] + dp[n][1] + dp[n][2])%9901 <<endl;


    return 0;
}
