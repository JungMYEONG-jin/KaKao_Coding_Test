using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    int n = 0;
    int i = 1;
    while(n<count)
    {
        answer+=(i*price);
        n++;
        i++;
    }
    
    
    
    return answer>money?answer-money:0;
}
