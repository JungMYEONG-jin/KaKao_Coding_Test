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

int main()
{
    int ans = 0;
    int a, b;
    cin>>a;
    cin>>b;
    int save = a;
    int value = a*a;
    int cnt = 0;
    int dp[1000][1000] = {0};
    int x, y = 0;
    while(value>0){
        x = cnt;
        for(int i=y;i<a;i++){
            dp[i][cnt] = value--;
        }
        y = a - 1;
        for(int i=x+1;i<a;i++){
            dp[y][i] = value--;
        }
        x = a-1;
        for(int i=y-1;i>=cnt;i--){
            dp[i][x] = value--;
        }
        y = cnt;
        for(int i = x-1;i>cnt;i--){
            dp[y][i] = value --;
        }
        cnt++;
        a--;
        y = cnt;
    }

    for(int i=0;i<save;i++){
        for(int j=0;j<save;j++){
            if (dp[i][j]==b)
            {
                x = i+1;
                y = j+1;
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<x<<" "<<y;
    return 0;
}
