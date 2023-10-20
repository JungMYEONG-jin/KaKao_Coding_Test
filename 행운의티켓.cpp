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
    string a;
    cin>>a;
    int left, right = 0;
    int s, e = 0;
    int start, mid, end;
    end = a.length() % 2 == 0 ? a.length() : a.length() - 1;
    end+=2;

    while(end>2){
        start = 0;
        end -= 2;
        e = end;
        s = start;
        while(e <= a.length()){
            mid = (s + e) >>1;
            left = 0;
            right = 0;

            for(int i=s;i<mid;i++){
                left += a[i] - '0';
            }

            for(int i=mid;i<e;i++){
                right += a[i] - '0';
            }

            if(left == right){
                cout<<end;
                return 0;
            }
            s++;
            e++;
        }
    }
    cout<<ans;
    return 0;
}
