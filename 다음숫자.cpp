#include <string>
#include <vector>
#include <iostream>

using namespace std;

int get_1(int n)
{
    int count=0;
    while(n)
    {
        if(n%2==1)
            count++;
        n/=2;
    }
    return count;
}




int solution(int n) {
    int answer = n+1;
    int goal = get_1(n);
    while(true)
    {
        if(goal==get_1(answer))
            break;
        answer++;
    }

    return answer;
}
