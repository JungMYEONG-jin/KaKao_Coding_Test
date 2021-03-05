#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), [](auto e, auto k){return e[1]<k[1];});

    int cam = -30001;
    
    for(auto i : routes)
    {
        if(cam<i[0])
        {
            answer++;
            cam = i[1];
        }
    }
    
    
    return answer;
}
