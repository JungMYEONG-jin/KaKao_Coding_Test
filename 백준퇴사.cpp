#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int day[17] = {0, };
    int pay[17] = {0, };
    for(int i=1;i<=n;i++)
        cin>>day[i]>>pay[i];
    
    int ans = 0;
    for(int i=n;i>=1;i--)
    {
        if(i+day[i]>n+1)
            pay[i] = pay[i+1];
        else
        {
            pay[i] = max(pay[i+1], pay[i]+pay[i+day[i]]);
            ans = max(ans, pay[i]);
        }
    }
    
    cout<<ans<<endl;
    return 0;
}
