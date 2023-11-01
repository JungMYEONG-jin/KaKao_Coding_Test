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


vector<int> arr[10001];
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
    string s;
    cin>>s;
    int cnt = 0;
    string temp = "";
    for(int i=0, len = s.size(); i<len; i++){
        if(s[i]=='X'){
            cnt++;
        }else if(s[i]=='.'){
            if(cnt%2 == 1){
                cout<<-1<<endl;
                return 0;
            }else{
                // even
                // check 4
                int four = cnt/4;
                int second = (cnt%4)/2;
                for(int j=0;j<four;j++){
                    temp+="AAAA";
                }
                for(int j=0;j<second;j++){
                    temp+="BB";
                }
            }
            temp+='.';
            cnt = 0;
        }
    }
    if(cnt%2 == 1){
        cout<<-1<<endl;
        return 0;
    }

    // even
    // check 4
    int four = cnt/4;
    int second = (cnt%4)/2;
    for(int j=0;j<four;j++){
        temp+="AAAA";
    }
    for(int j=0;j<second;j++){
        temp+="BB";
    }
    
    cout<<temp<<endl;
    return 0;
}
