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

void dfs(int start, int end, bool* visited, int* arr){
    if(start < 1 || start > end){
        return;
    }
    visited[start] = true;
    dfs(start + arr[start], end, visited, arr);
    dfs(start - arr[start], end, visited, arr);
}

int main()
{
    bool visited[100001] = {false};
    int arr[100001] = {0};
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int start;
    cin>>start;
    dfs(start, n, visited, arr);
    int answer = 0;
    for(int i=1;i<=n;i++){
        if (visited[i])
        {
            answer++;
        }
        
    }
    cout<<answer;
    return 0;
}
