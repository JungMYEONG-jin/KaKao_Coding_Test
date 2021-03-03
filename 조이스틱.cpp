#include <vector>
#include <string>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int n;
    cin>>n;
    string str;
    auto trans = [](char ch){return 65+(ch-'A'+25)%26;}; // 아래로 내리는 경우
    for(int i=0;i<n;i++)
    {
        cin>>str;
        int len = str.size();
        int sum=0;
        
        if(count(str.begin(), str.end(), 'A')==len)
        {
            cout<<0<<'\n';
            continue;
        }
        
        
        // 우선 각 문자에 대해 얼마나 이동해야 하는지 탐색
        for(auto i : str)
        {
            if(i>='A' && i<='N')
            {
                sum+=(i-'A');
            }else if(i>='O' && i<='Z')
            {
                char ch = 'A';
                int count=0;
                while(ch!=i)
                {
                    ch = trans(ch);
                    count++;
                }
                sum+=count;
            }
        }
        
        // 탐색후 좌우로 얼마만큼 최소로 움직여야 하는지 탐색
        int move = len-1;
        for(int i=0;i<len;i++)
        {
           int next = i+1;
            while(next<len && str[next]=='A')
                next++;
            if(str[i]=='A' && next==len+1) break;
            int left = i*2+len-next;
            int right = i+(len-next)*2;
            int val = min(left, right);
            move = min(move, val);
        }
        sum+=move;
        
        cout<<sum<<'\n';
        
        
    }
    
    
    
}
