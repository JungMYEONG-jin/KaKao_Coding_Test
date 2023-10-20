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
    int ans = 0;
    int a, b;
    cin>>a>>b;
    vector<string> arr;
    for(int i=0;i<a;i++){
        string s;
        cin>>s;
        arr.push_back(s);
    }

    int sx, sy;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if (arr[i][j] == 'I')
            {
                sx = i;
                sy = j;
            }
        }
    }
    vector<vector<bool>> visited(a, vector<bool>(b, false));
    queue<pair<int, int>> q;
    q.push({sx, sy});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int x = it.first;
        int y= it.second;
        visited[x][y] = true;
        if(arr[x][y]=='P'){
            ans++;
        }

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx<0 || nx>=a || ny<0 || ny>=b)
                continue;
            if(arr[nx][ny]=='X')
                continue;
            if (!visited[nx][ny])
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    if (ans == 0)
    {
        cout<<"TT";
    }else{
        cout<<ans;
    }
    return 0;
}
