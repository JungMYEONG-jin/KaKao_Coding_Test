#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;

    vector<tuple<int, int, int, double>> res; // 번호 무거운복서이긴횟수 몸무게 승률

    for(int i=0,len=weights.size();i<len;i++)
    {
        
        int cnt = 0;
        int cnt_N = count(head2head[i].begin(), head2head[i].end(), 'N');
        
        int len2 = len-cnt_N;
        int heavy = 0;
        double rate = 0.0;
        if(len2>0)
        {   
            for(int j=0;j<len;j++)
            {
                if(head2head[i][j]=='W'r)
                {
                    cnt++;
                    if(weights[i]<weights[j])
                        heavy++;
                }
            }
            rate = (cnt)/(len2+0.0);
        }
        res.push_back({i+1, heavy, weights[i], rate});
    }
    
    sort(res.begin(), res.end(), [](auto e, auto k){
       return get<3>(e) > get<3>(k) || get<3>(e)==get<3>(k) && get<1>(e) > get<1>(k) ||
            get<3>(e)==get<3>(k) && get<1>(e) == get<1>(k) && get<2>(e) > get<2>(k) ||
           get<3>(e)==get<3>(k) && get<1>(e) == get<1>(k) && get<2>(e) == get<2>(k) && get<0>(e) < get<0>(k);
    }); //정렬
    
    for(auto& i : res)
        answer.push_back(get<0>(i)); // 번호
    
    return answer;
}
