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

int main()
{
    int ans = 0;
    string a, b;
    cin>>a>>b;
    
    if (a.size() != b.size())
    {
        cout<<0;
        return 0;
    }

    for(int i=0, len = a.size(); i<len; i++){
        if (a[i]==b[i] && a[i]=='8')
        {
            ans++;
        }else if(a[i]!=b[i]){
            break;
        }
    }
    
    cout<<ans;
    return 0;
}
