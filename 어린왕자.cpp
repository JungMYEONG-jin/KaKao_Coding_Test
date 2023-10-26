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

int main()
{
    // input
    ios_base::sync_with_stdio(0);
	cin.tie(0); 
    cout.tie(0);
    // int n, m;
    int t;
    int sx, sy, ex, ey;
    int a, b, r;
    int dep, join;
    cin>>t;
    while(t--){
        dep = 0;
        join = 0;
        cin>>sx>>sy>>ex>>ey;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a>>b>>r;
            if((sx-a) * (sx-a) + (sy-b) * (sy-b) < r*r){
                if((ex-a)*(ex-a) + (ey-b)*(ey-b) > r*r){
                    dep++;
                }
            }

            if((sx-a) * (sx-a) + (sy-b) * (sy-b) > r*r){
                if((ex-a)*(ex-a) + (ey-b)*(ey-b) < r*r){
                    join++;
                }
            }

        }
        cout<<dep+join<<endl;
    }
    return 0;
}
