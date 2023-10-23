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
    int answer = INF;
    int arr[1000001];
    fill_n(arr, 1000001, INF);
    int start, end;
    cin>>start>>end;
    
    queue<pair<int, int>> q;
    q.push({start, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int cur = it.first;
        int cnt = it.second;
        if (cur == end)
        {
            answer = min(answer, arr[cur]);
        }
        if(cur+1 <= end && arr[cur+1] > cnt+1){
            q.push({cur+1, cnt+1});
            arr[cur+1] = cnt+1;
        }
        if(2*cur <= end && arr[2*cur] > cnt+1){
            q.push({2*cur, cnt+1});
            arr[2*cur] = cnt+1;
        }
    }
    
    cout<<answer;

    return 0;
}
