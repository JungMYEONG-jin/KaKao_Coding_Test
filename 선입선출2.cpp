#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> cores) {
    int answer = 0;
    int left = 0;
    int right = 2e6;
    // n에 근접하는 최대 타임을 구하자
    while(left<right){
        int mid = (left+right)>>1;
        int cnt = 0;
        int av = 0;
        for(auto core : cores){
            cnt+=mid/core+1;
            if(mid%core==0)
            {
                av++;
                cnt--;
            }
        }
        
        if(cnt>=n){
            right = mid;
        }else if(cnt+av<n){
            left = mid+1;
        }else{
            int idx = 0;
            for(auto core : cores){
                if(mid%core==0)
                    cnt++;
                if(cnt==n){
                    return idx+1;
                }
                idx++;
            }
        }
    }
return answer;
}
