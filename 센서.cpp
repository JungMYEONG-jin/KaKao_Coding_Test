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


vector<int> arr[10001];
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
    int n, k;
    cin>>n>>k;
    vector<int> censors(n);
    vector<int> diff(n-1);
    for(int i=0;i<n;i++)
        cin>>censors[i];

    if(k>n)
    {
        cout<<0<<endl;
        return 0;
    }
    
    sort(censors.begin(), censors.end());
    for(int i=0;i<n-1;i++){
        diff[i] = censors[i+1] - censors[i];
    }

    sort(diff.begin(), diff.end());
    int ans = 0;
    for(int i=0;i<n-k;i++)
        ans+=diff[i];

    cout<<ans<<endl;

    return 0;
}
