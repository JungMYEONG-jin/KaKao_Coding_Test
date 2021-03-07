#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int tot = brown+yellow;
    int n = tot/2;
    while(true)
    {
        if(tot%n==0)
        {
            int m = tot/n;
            if(n*m==(brown+yellow) && (n-2)*(m-2)==yellow)
            {
                answer.push_back(n);
                answer.push_back(m);
                return answer;
            }
        }

        n--;

    }



    return answer;
}
