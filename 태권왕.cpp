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

int getMinKickCount(int start, int end){
    queue<tuple<int, int, int>> q;
    q.push({start, 0, end});
    int ans = INF;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int cur = get<0>(it);
        int cnt = get<1>(it);
        int curEnd = get<2>(it);

        if (cur > curEnd){
            continue;
        }
        
        if(cur == curEnd){
            ans = min(ans, cnt);
            break;
        }
       
        q.push({2*cur, cnt+1, curEnd+3});
        q.push({cur+1, cnt+1, curEnd});
    }
    return ans == INF ? 0 : ans;
}

int main()
{
    int n;
    int start, end;
    cin>>n;
    vector<int> result;
    for(int i=0;i<n;i++){
        cin>>start>>end;
        result.push_back(getMinKickCount(start, end));
    }

    for(const auto i : result){
        cout<<i<<endl;
    }

    return 0;
}
