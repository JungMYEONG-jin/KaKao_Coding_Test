#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int left = 0;
    int right = 0;
    int len = sequence.size() + 1;
    int sum = sequence[0];
    answer.push_back(left);
    answer.push_back(right);
    while(left<=right && right < sequence.size()){
        if (sum == k)
        {
            if (right - left + 1 < len)
            {
                len = right - left + 1;
                answer[0] = left;
                answer[1] = right;
            }else if(right - left + 1 ==len){
                if (left < answer[0])
                {
                    answer[0] = left;
                }
            }
            sum -= sequence[left++];
        }else if(sum > k){
            sum -= sequence[left++];
        }else{
            sum+=sequence[++right];
        }
    }

    return answer;
}
