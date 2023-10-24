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

int dp[100001];

int main()
{
    // input
    ios_base::sync_with_stdio(0);
	cin.tie(0); 
    cout.tie(0);
    int n, m, a, b;
    cin>>n>>m>>a>>b;
    
    bool canVisited[100001];
    fill_n(canVisited, 100001, true);


    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        for(int j=x;j<=y;j++)
        {
            if(canVisited[j]){
                canVisited[j] = false;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();

        int cur = it.first;
        int cnt = it.second;
        // canVisited[cur] = false;

        if(cur>n)
            break;

        if (cur == n)
        {   
            cout<<cnt<<endl;
            return 0;
        }

        if(cur+b <= n && canVisited[cur+b]){
            q.push({cur+b, cnt+1});
            canVisited[cur+b] = false;
        }
        if(cur + a <= n && canVisited[cur+a]){
            q.push({cur + a, cnt+1});
            canVisited[cur+a] = false;
        }
    }
    cout<<-1<<endl;

    return 0;
}
