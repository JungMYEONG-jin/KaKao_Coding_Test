#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int i=1;
    while(i<=n)
    {
        int j=i;
        int sum=j;
        while(sum<n)
        {
            j++;
            sum+=j;
            
        }
        if(sum==n)
            answer++;
        i++;
    }
    
    
    
    
    
    
    return answer;
}
