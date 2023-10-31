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
#include <cstring>

#define INF 999999999

using namespace std;


vector<int> arr[101];
bool visited[101];
int blue = 0;
int white = 1;
int n;
long long dp[101];

int main()
{
    // input
    ios_base::sync_with_stdio(0);
	cin.tie(0); 
    cout.tie(0);
    string input;
    cin>>input;

    vector<string> arr;
    for(int i=0, len = input.size();i<len;i++){
        arr.push_back(input.substr(i));
    }

    sort(arr.begin(), arr.end());
    for(const auto& text : arr)
    {
        cout<<text<<'\n';
    }
    

    return 0;
}
