#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    int tot_sec = prices.size()-1;
    answer.resize(tot_sec+1);
    answer[tot_sec]=0;
    for(int i=0;i<tot_sec;i++)
    {
        int val = prices[i];
        auto it = find_if(prices.begin()+i, prices.end(), [val](auto e){return e<val;});
        if(it==prices.end())
            answer[i]=tot_sec-i;
        else
            answer[i] = (it-prices.begin())-i;
    }



    return answer;
}

/* 문제 의도에 맞게 stack을 사용한 코드


vector<int> solution(vector<int> prices) {
    vector<int> answer;

    stack<int> res;
    int len = prices.size();
    answer.resize(len);
    
    for(int i=0;i<len;i++)
    {
      while(!res.empty() && prices[res.top()]>prices[i])
      {
        answer[res.top()] = i-res.top();
        res.pop();
      
      }
    
    
      res.push(i);
    }
    
    while(!res.empty())
    {
      answer[res.top()] = len-res.top()-1;
      res.pop();
    
    }



    return answer;
}


*/
