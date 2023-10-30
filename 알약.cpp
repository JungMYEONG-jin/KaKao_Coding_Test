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
long long dp[31][31];

void init(){
    for(int i=0;i<=30;i++){
        dp[0][i] = 1;
    }

    for(int w=1;w<=30;w++){
        for(int h=0;h<=30;h++){
            if (h == 0)
            {
                dp[w][0] = dp[w-1][1];
            }else{
                dp[w][h] = dp[w-1][h+1] + dp[w][h-1];
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

    init();

    while(true){
        cin>>n;
        if (n == 0)
        {
            return 0;
        }

        cout<< dp[n][0]<<'\n';
    }

    return 0;
}
