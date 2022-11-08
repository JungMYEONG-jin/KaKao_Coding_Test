#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<pair<int, int>> res;
    res.push_back({0, k});
    int idx = 1;
    while(k!=1){
        if (k%2==0)
        {
            /* code */
            k/=2;
            res.push_back({idx++, k});
        }else{
            k = 3*k+1;
            res.push_back({idx++, k});
        }       
    }

    vector<double> dist;
    for(int i=0, len=res.size();i<len-1;i++){
        dist.push_back((res[i].second+res[i+1].second)*(1)/(2+0.0));
    }

    // last offset
    idx -= 1;
    for(auto range : ranges){
        int left = range[0];
        int right = idx + range[1];
        if(left>right)
            answer.push_back(-1.0);
        else if(left==right)
            answer.push_back(0.0);
        else
            answer.push_back(static_cast<double>(accumulate(dist.begin()+left, dist.begin()+right, 0.0)));
    }
    return answer;
}
