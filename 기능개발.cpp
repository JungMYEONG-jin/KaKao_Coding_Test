#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int len = progresses.size();
    // 연속 감소 하는지 확인하는지 check
    // 주식가격이랑 비슷함!!
    // 어차피 배열 개수 100개라 시간초과는 없을듯함

    vector<int> time(len);
    for(int i=0;i<len;i++)
    {
        int day = ceil(static_cast<double>(100-progresses[i])/speeds[i]);
        time[i] = day;
    }

    for(int i=0;i<len;i++)
    {
        int build=1;
        for(int j=i+1;j<len;j++)
        {
            if(time[j]<=time[i])
            {
                build++;
                if(j==len-1)
                    i=j;
            }
            else{
                i=j-1;
                break;
            }
        }
        answer.push_back(build);
    }





    return answer;
}



/*
// 큐를 사용했을때

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int len = progresses.size();
    // 연속 감소 하는지 확인하는지 check
    // 주식가격이랑 비슷함!!
    // 어차피 배열 개수 100개라 시간초과는 없을듯함
    
    queue<int> time;
    for(int i=0;i<len;i++)
    {
        int day = ceil(static_cast<double>(100-progresses[i])/speeds[i]);
        time.push(day);
    }
    
    while(!time.empty())
    {
        int cur = time.front();
        time.pop();
        int build=1;
        
        while(!time.empty() && cur>=time.front())
        {
            build++;
            time.pop();
        }
        answer.push_back(build);
    }
    
    
    
    
    
    return answer;
}



//추천수 제일 많은 코드


#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int len = progresses.size();
    // 연속 감소 하는지 확인하는지 check
    // 주식가격이랑 비슷함!!
    // 어차피 배열 개수 100개라 시간초과는 없을듯함
    
    int day;
    int maxDay=0;
    for(int i=0;i<len;i++)
    {
        day = ceil(static_cast<double>(100-progresses[i])/speeds[i]);
        
        
        if(answer.empty() || maxDay<day)
          answer.push_back(1);
        else
          ++answer.back();
        
        
        if(maxDay<day)
          maxDay=day;
    }
    
    
    
    
    
    
    
    return answer;
}


*/
