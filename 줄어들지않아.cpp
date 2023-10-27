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

long dp[66][10];

int main()
{
    // input
    ios_base::sync_with_stdio(0);
	cin.tie(0); 
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<10;i++){
        dp[1][i] = 1;
    }

    for(int i=2;i<=65;i++){
        for(int j=0;j<10;j++){
            for(int k=j;k>=0;k--){
                dp[i][j] += dp[i-1][k];
            }
        }
    }

    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        long long sum = 0;
        for(int i=0;i<10;i++)
            sum+=dp[t][i];
        cout<<sum<<endl;
    }
    return 0;
}
