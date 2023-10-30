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


vector<int> arr[101];
bool visited[101];
int blue = 0;
int white = 1;
int n;
long long dp[101];



int main()
{
    // input
    ios_base::sync_with_stdio(0);
	cin.tie(0); 
    cout.tie(0);
    cin>>n;

    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    dp[4]=4;
    dp[5]=5;
    dp[6]=6;

    for(int i=7;i<=n;i++){
        for(int j=3;i-j>0;j++){
            dp[i] = max(dp[i-j]*(j-1), dp[i]);
        }
    }
    cout<<dp[n]<<endl;

    return 0;
}
