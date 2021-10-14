#include <string>
#include <vector>
#include <algorithm>
#include <set>

#define INF 999999999

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = INF;
    int len = weak.size();
    int dlen = dist.size();
    
    for(int i =0;i<len-1;i++)
        weak.push_back(weak[i]+n);
   
    do{
        for(int i=0;i<len;i++)
        {
            int idx = 0;
            int cur = weak[i]+dist[idx];
            bool flag = true;
            for(int j=i+1;j<len+i;j++)
            {
                if(cur<weak[j])
                {
                    if(idx==dlen-1) // 아직 덜 돌았는데 idx가 부족하면 돌지못하는거임!
                    {
                        flag = false;
                        break;
                    }else
                        cur = weak[j]+dist[++idx];
                }
            }
            if(flag)
                answer = min(answer, idx+1);
        }
        
    }while(next_permutation(dist.begin(), dist.end()));
    
    if(answer==INF)
        return -1;
    
    return answer;
}
