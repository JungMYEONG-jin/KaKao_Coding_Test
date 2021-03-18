#include <string>
#include <vector>
#include <iostream>
#include <algorithm>




using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    int len = money.size();

    int coin[n+1];

    for(int i=0;i<=n;i++)
    {
        coin[i]=(i%money[0]==0)?1:0;
    }

    for(int i=1;i<len;i++)
    {
        for(int j=money[i];j<=n;j++)
            coin[j]+=coin[j-money[i]];
    }

    answer = coin[n]%1000000007;

    return answer;
}

