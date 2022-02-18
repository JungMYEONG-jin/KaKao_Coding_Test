#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n, m;
int arr[9];
bool visited[9];
vector<int> res;



void trace(int cnt)
{
    if(cnt==m)
    {
        for(int i=0;i<m;i++)
            cout<<arr[i]<<" ";
        cout<<'\n';
    }
    
    for(int i=0;i<res.size();i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            arr[cnt] = res[i];
            trace(cnt+1);
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        res.push_back(x);
    }
    sort(res.begin(), res.end());
    trace(0);
}
