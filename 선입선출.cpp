#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> cores) {
    int answer = 0;
    int left = -1;
    int right = 2e5;
    int len = cores.size();
    while(left+1<right){
        int mid = (left+right)>>1;
        int cnt = len;
        if (mid>0)
        {
            /* code */
            for(auto core : cores){
                cnt+=mid/core;
            }
        }
        if (cnt<n)
        {
            /* code */
            left = mid;
        }else
            right = mid;
    }

    if(left==-1)
        return n;
    int cnt = len;
    for(auto core : cores)
        cnt+=left/core;
    for(int i=0;i<len;i++){
        if((left+1)%cores[i]==0)
            cnt++;
        if (cnt==n)
        {
                /* code */
            return i+1;
        }
            
    }

    return answer;
}
