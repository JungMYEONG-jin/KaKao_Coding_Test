#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int len = score.size()-1;
    sort(score.begin(), score.end());
    for(int i=len;i>=0;i-=m){
        if(i<=0)
            break;
        int ans = *min_element(score.begin()+i-m+1, score.begin()+i+1);
        answer+=m*ans;
    }
    return answer;
}
