#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long solution(vector<int> money) {
    long long answer = 0;
    
    
    // 0이 포함될때
    // 1이 포함될때 구분해서 해야겠지?
    long long sum=0;
    int len = money.size();
    long long house[1000001];
    //memset(house, 0, sizeof(house));
    for(int i=0;i<len-1;i++)
    {
        // 0부터 시작시 len-1은 안됨 0과 len-1이 이웃이니까!
        if(i<1) house[i] = money[i];
        else
            house[i] = max(money[i]+house[(i + len - 2) % len], house[(i + len - 1) % len]);
        
        sum = max(sum, house[i]);
    }
    
    long long house2[1000001];
    //memset(house2, 0, sizeof(house2));
    long long sum2=0;
    
    
    for(int i=1;i<len;i++)
    {
       
        house2[i] = max(money[i]+house2[(i + len - 2) % len], house2[(i + len - 1) % len]);
        
        sum2 = max(sum2, house2[i]);
    }
  
    answer = max(house[len-2], house2[len-1]);
    return answer;
}
