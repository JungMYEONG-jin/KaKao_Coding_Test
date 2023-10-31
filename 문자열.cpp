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
    string left, right;
    cin>>left>>right;
    int ans = INF;
    for(int i=0, len = right.size() - left.size();i<=len;i++){
        int cnt = 0;
        for(int j=0;j<left.size();j++){
            if (left[j] != right[j+i])
            {
                cnt++;
            }
        }
        ans = min(ans, cnt);
    }
    cout<<ans<<endl;
    

    return 0;
}
