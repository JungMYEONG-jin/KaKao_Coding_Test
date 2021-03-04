#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    deque<char> res;
    int cnt=0;
    int len = number.size()-k;


    for(auto i : number)
    {
        while(k && !res.empty() && res.back()<i)
        {
            k--;
            res.pop_back();
        }


        res.push_back(i);
    }


    for(int i=0;i<res.size();i++)
        answer+=res[i];





    return answer.substr(0, len);
}

