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

int dist[51][51];
int graph[51][51];

int main()
{
    int ans = 0;
    int n;
    cin>>n;

    for(int i=0;i<51;i++){
        fill_n(dist[i], 51, INF);
    }

    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        for(int j=0, len = temp.size();j<len;j++){
            if (temp[j]=='Y')
            {
                graph[i][j] = 1;
                dist[i][j] = 1;
            }else{
                graph[i][j] = 0;
            }
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                } 
            }
        }
    }

    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if (i==j)
            {
                continue;
            }
            if (dist[i][j]<=2)
            {
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }

    cout<<ans;


    
    return 0;
}
