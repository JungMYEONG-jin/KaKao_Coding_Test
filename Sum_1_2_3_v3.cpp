#include <iostream>

using namespace std;

long divs = 1000000009;
long dp[1000001];

int main()
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    int n;
    cin>>n;
    int k;
    for(int i=4;i<=1000000;i++)
    {
        dp[i] = (dp[i-1]+dp[i-2]+dp[i-3])%divs;
    }
    for(int i=0;i<n;i++)
    {
        cin>>k;
        cout<<dp[k]<<endl;
    }
    
    return 0;
    
}
