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

void isOne(vector<int>& arr){
    if (arr.size() == n)
    {
        cout<< n-1 <<"\n";
        for(int i=0, len = arr.size(); i< len-1;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        cout<<1<<"\n"<<arr.back()<<"\n";
        exit(0);
    }
}


int main()
{
    // input
    ios_base::sync_with_stdio(0);
	cin.tie(0); 
    cout.tie(0);
    cin>>n;
    
    for(int i=1;i<=n;i++){
        int hateNumber;
        int num;
        cin>>hateNumber;
        while(hateNumber--){
            cin>>num;
            arr[i].push_back(num);
            arr[num].push_back(i);
        }
    }

    vector<int> blues, whites;

    for(int i=1;i<=n;i++){
        if (visited[i])
        {
            continue;
        }

        visited[i] = true;
        blues.push_back(i);

        queue<int> q;
        q.push(i);

        int team = white;

        while (!q.empty())
        {
            int qs = q.size();
            for(int j=0;j<qs;j++){
                int cur = q.front();
                q.pop();

                for(const auto hate : arr[cur]){
                    if (visited[hate])
                    {
                        continue;
                    }
                    visited[hate] = true;
                    team == white ? whites.push_back(hate) : blues.push_back(hate);
                    q.push(hate);
                }
            }
            team = (team == white) ? blue : white;
        }    
    }

    sort(blues.begin(), blues.end());
    sort(whites.begin(), whites.end());

    // check if is one sided
    isOne(blues);
    isOne(whites);

    cout<<blues.size()<<"\n";
    for(const auto people : blues)
        cout<<people<<" ";

    cout<<"\n";

    cout<<whites.size()<<"\n";
    for(const auto people : whites)
        cout<<people<<" ";

    return 0;
}
