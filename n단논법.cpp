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

vector<int> arr[26];

bool bfs(int left, int right){
    queue<int> q;
    q.push(left);
    bool visited[26] = {false};
    visited[left] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto next : arr[x]){
            if (visited[next])
            {
                continue;
            }
            visited[next] = true;
            q.push(next);
        }
    }
    return visited[right];
}

int main()
{
    // input
    int n, m;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        string s;
        getline(cin, s);
        char left = s[0];
        char right = s[s.size() - 1];
        arr[left-'a'].push_back(right-'a');
    }
    cin>>m;
    cin.ignore();
    for(int i=0;i<m;i++){
        string s;
        getline(cin, s);
        int left = s[0] - 'a';
        int right = s[s.size()-1] - 'a';
        if(bfs(left, right)){
            cout<<"T\n";
        }else{
            cout<<"F\n";
        }
    }


    return 0;
}
