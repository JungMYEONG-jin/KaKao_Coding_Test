#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <regex>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> res;

    regex re("\\{|\\}");

    s = regex_replace(s, re, "");

    // 갯수가 가장 많은 원소가 시작지점일것임

    stringstream sstr(s);
    string temp;

    while(getline(sstr, temp,','))
    {
        res[stoi(temp)]++;
    }
    map<int, int, greater<int>> res2;
    for(auto& it : res)
        res2[it.second] = it.first;

    for(auto& it : res2)
        answer.push_back(it.second);




    return answer;
}
