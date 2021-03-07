#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <set>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    long long last_time = times[times.size()-1];
    long long max_val = last_time*n;
    long long right = max_val;
    long long left=1;
    long long result = max_val;
    int len = times.size();
    while(left<=right)
    {
        long long mid = (left+right)/2;
        long long tot=0;
        for(int i=0;i<len;i++)
        {
            tot+=mid/times[i];
        }
        
        if(tot<n)
            left = mid+1;
        else
        {
            result = min(result, mid);
            right = mid-1;
        }
    }
    
    answer = result;
    
    return answer;
}
