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

int dp[1009] = {0,};

int main()
{
    // input
    ios_base::sync_with_stdio(0);
	cin.tie(0); 
    cout.tie(0);
    int n;
    cin>>n;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    dp[4] = 1;
    

    for(int i=5;i<=n;i++){
        if (dp[i-1] == 1 || dp[i-4] == 1 || dp[i-3] == 1){
            dp[i] = 0;
        }else{
            dp[i] = 1;
        }
    }

    if (dp[n])
    {
        cout<<"SK";
    }else
    {
        cout<<"CY";
    }
    

    return 0;
}
