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

vector<vector<int>> graph(51, vector<int>(51, 0));

int main()
{
    int n;
    vector<int> arr;
    int x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    int m;
    cin>>m;

    for(auto i : arr){
        if (i == m)
        {
            cout<<0;
            return 0;
        }
    }

    arr.push_back(m);
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = 0;
    for(int i=0;i<arr.size();i++){
        if (arr[i] == m)
        {
            left = arr[i-1];
            right = arr[i+1];
            break;
        }
    }

    int ans = 0;

    for(int i = left+1;i<=m;i++){
        for(int j=m;j<right;j++){
            if (i==j)
            {
                continue;
            }
            ans++;
        }
    }

    
    cout<<ans<<endl;
    return 0;
}
