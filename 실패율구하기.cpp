#include <string>
#include <vector>
#include <algorithm>
#include <numeric>


using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    vector<pair<int, double>> res;

    for(int i=1;i<=N;i++)
    {
        //int k = i;
        int n1 = count_if(stages.begin(), stages.end(), [i](auto e){return e>=i;});
        int n2 = count(stages.begin(), stages.end(), i);

        // n1 total
        // n2 not cleared
        if(n1!=0)
            res.push_back({i, n2/(static_cast<double>(n1))});
        else
            res.push_back({i, 0});
    }


    sort(res.begin(), res.end(), [](auto e, auto k){
        return e.second>k.second || e.second==k.second && e.first<k.first;
    });

    for(auto i : res)
        answer.push_back(i.first);


    return answer;
}
