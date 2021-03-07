#include <string>
#include <vector>
#include <queue>



using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> res;

    for(auto i : scoville)
        res.push(i);

    int count=0;
    while(res.size()>1)
    {

        while(!res.empty() && res.top()>=K)
            res.pop();


        if(res.size()<=1)
            break;


        int a = res.top();
        res.pop();
        int b = res.top();
        res.pop();
        int sco = a+2*b;
        res.push(sco);
        count++;

    }

    if(!res.empty() && res.top()<K)
        return -1;

    answer=count;

    return answer;
}
