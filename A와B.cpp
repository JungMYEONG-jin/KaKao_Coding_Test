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

int main()
{
    // input
    ios_base::sync_with_stdio(0);
	cin.tie(0); 
    cout.tie(0);
    string s, t;
    cin>>s;
    cin>>t;

    bool isSame = false;

    while(true){
        if (s.size() == t.size())
        {
            if (s == t)
            {
                isSame = true;
            }
            break;
        }

        if(t.back() == 'A'){
            t.pop_back();
        }else{
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }


    cout<<isSame<<endl;


    return 0;
}
