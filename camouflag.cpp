#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    map<string ,int> res;
    for(auto& i : clothes)
    {
        res[i[1]]++; // headgear eyewear etc...
    }
    
    int sum=1;
    for(auto it : res)
        sum*=(it.second+1);
    
    
    
    return sum-1;
}

// 그냥 단순히 조합 개념으로 풀었는데 이게 왜 hash지
// 다른 사람 풀이 참고했는데 다 이렇게 했네
// 근데 점수를 너무 짜게 준다;;


