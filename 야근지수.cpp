#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    priority_queue<int> res;

    for(auto i : works)
        res.push(i);

    while(n)
    {
        int mval = res.top();
        res.pop();
        mval--;
        if(mval>0)
            res.push(mval);
        if(res.empty())
            return 0;
        n--;
    }


    while(!res.empty())
    {
        answer+=pow(res.top(), 2);
        res.pop();
    }


    return answer;
}
