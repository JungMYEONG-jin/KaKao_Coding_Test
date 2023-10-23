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
    int answer = 0;
    bool visited[100001] = {false};
    int arr[100001] = {0};
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int start, end;
    cin>>start>>end;
    
    queue<pair<int, int>> q;
    q.push({start, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int cur = it.first;
        int cnt = it.second;
        int val = arr[cur];
        if (cur == end)
        {
            answer = cnt;
            break;
        }
        visited[cur] = true;

        // right
        for(int i = 1 ; cur + (i * val) <=n; i++){
            int next = cur + (i * val);
            if (!visited[next])
            {
                q.push({next, cnt+1});
            }
        }

        for(int i = 1; cur - (i * val) >=1 ;i++){
            int next = cur - (i * val);
            if (!visited[next])
            {
                q.push({next, cnt+1});
            }
            
        }


    }
    if (answer == 0)
    {
        cout<<-1;
    }else{
        cout<<answer;
    }
    return 0;
}
