#include <string>
#include <regex>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    string left="";
    string right="";

    transform(str1.begin(), str1.end(),str1.begin(), [](auto e){return tolower(e);});
    transform(str2.begin(), str2.end(),str2.begin(), [](auto e){return tolower(e);});

    left = str1;
    right = str2;


    vector<string> l;
    vector<string> r;

    for(int i=0;i<left.size()-1;i++)
    {
        auto k = left.substr(i, 2);
        if(isalpha(k[0]) && isalpha(k[1]))
            l.push_back(k);
    }
    for(int i=0;i<right.size()-1;i++)
    {
        auto k = right.substr(i, 2);
        if(isalpha(k[0]) && isalpha(k[1]))
            r.push_back(k);
    }



    vector<string> insec;

    int len1 = l.size();
    int len2 = r.size();

    int min_count=0;

    map<string, int> map1;
    map<string, int> map2;

    for(auto i : l)
        map1[i]++;
    for(auto i : r)
        map2[i]++;


    for(auto& it : map1)
    {
        if(map2[it.first])
            min_count+=min(it.second, map2[it.first]);
    }






    if(l.empty() && r.empty())
        return 65536;


    answer = (min_count/double(len1+len2-min_count))*65536;

    return answer;
}
