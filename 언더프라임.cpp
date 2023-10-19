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
    int a, b;
    cin>>a>>b;
    bool prime[100001];
    fill_n(prime, 100001, true);
    prime[0] = false;
    prime[1] = false;

    int arr[100001] = {0};
    int ans = 0;

    for(int i=2;i<=100000;i++){
        if (prime[i])
        {
            for(int j=2*i;j<=b;j+=i){
                prime[j] = false;
                int cur = j;
                while (cur%i==0)
                {
                    cur/=i;
                    arr[j]++;
                }
            }
        }
    }

    for(int i=a;i<=b;i++){
        if (prime[arr[i]])
        {
            ans++;
        }
        
    }
    cout<<ans;

    return 0;
}
