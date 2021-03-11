#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <regex>


using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int len = arr1.size();
    for(int i=0;i<n;i++)
    {
        int k = arr1[i]|arr2[i];
        string res;
        while(k)
        {
            if(k%2==1)
                res+="#";
            else
                res+=" ";
            k/=2;
        }
        if(res.size()<n)
        {
            while(res.size()!=n)
                res+=" ";
        }
        reverse(res.begin(), res.end());
        //res = regex_replace(res, regex("^\0+"),"");
        //transform(res.begin(), res.end(), res.begin(), [](auto e){return e=='0'?' ':'#';});
        answer.push_back(res);
    }
    return answer;
}
