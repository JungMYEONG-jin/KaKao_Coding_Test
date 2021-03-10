#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>



using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> res;
    string op ="+-*";
    vector<char> exp, location;
    string num;
    for(auto i : expression)
    {
        if(op.find(i)!=op.npos)
        {
            res.push_back(stoll(num));
            exp.push_back(i);
            num="";
        }
        else
            num+=i;
    }
    res.push_back(stoll(num));
    location = exp;
    // 중복 제거




    sort(exp.begin(), exp.end());
    exp.erase(unique(exp.begin(), exp.end()), exp.end());



    // 연산자 모든 조합을 수열을 이용해 나타내줌
    long long maxval=0;
    do{
        auto res2 = res;
        auto location2 = location;

        for(auto i : exp)
        {
            for(int j=0;j<location2.size();j++)
            {
                if(i==location2[j])
                {
                    if(i=='+')
                        res2[j]+=res2[j+1];
                    else if(i=='-')
                        res2[j]-=res2[j+1];
                    else if(i=='*')
                        res2[j]*=res2[j+1];

                    res2.erase(res2.begin()+j+1);
                    location2.erase(location2.begin()+j);
                    j--;
                }
            }
        }
        maxval = max(maxval, abs(res2[0]));

    }while(next_permutation(exp.begin(), exp.end()));







    answer =maxval;


    return answer;
}
