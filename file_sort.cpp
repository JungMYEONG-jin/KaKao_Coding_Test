#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>

using namespace std;

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<tuple<string, int, int>> res;
    int idx=0;
    for(auto& i : files)
    {
        string str;
        for(int j=0;j<i.size();j++)
        {
            if(!isdigit(i[j]))
                str+=i[j];
            else
            {
                int k = j;
                string snum;
                while(isdigit(i[k]))
                {
                    snum+=i[k];
                    k++;
                }

                //string num = i.substr(j,k-j);
                int num = stoi(snum);
                //string rest = i.substr(k);
                //cout<<str<<" "<<num<<" "<<rest<<endl;
                auto it = make_tuple(str, num, idx);
                res.push_back(it);
                idx++;
                break;
            }
        }
    }


    sort(res.begin(), res.end(), [](auto e, auto k){

        string left = get<0>(e);
        string right = get<0>(k);

        transform(left.begin(), left.end(), left.begin(), [](auto t){return tolower(t);});
        transform(right.begin(), right.end(), right.begin(), [](auto t){return tolower(t);});

        return left<right || left==right && get<1>(e) < get<1>(k) || left==right && get<1>(e)==get<1>(k) &&get<2>(e)<get<2>(k);


    });





    for(auto i : res)
        answer.push_back(files[get<2>(i)]);







    return answer;
}
