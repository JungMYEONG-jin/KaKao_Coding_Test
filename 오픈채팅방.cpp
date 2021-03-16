#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <regex>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> db;
    map<string, vector<int>> res;
    int idx=0;
    for(auto& i : record)
    {
        auto it = i.find(' ');
        string k = i.substr(0, it);
        vector<string> temp;
        while(it!=i.npos)
        {
          auto prev = it;
          it = i.find(' ', prev+1);
          temp.push_back(i.substr(prev+1, it-prev-1));
        }
        if(temp.size()>1)
            db[temp[0]]=temp[1];
        else
            db[temp[0]];

        if(k=="Enter")
        {
            k="님이 들어왔습니다.";
            res[temp[0]].push_back(idx);
            idx++;
        }
        else if(k=="Leave")
        {
            k="님이 나갔습니다.";
            res[temp[0]].push_back(idx);
            idx++;

        }



        if(k!="Change")
            answer.push_back(temp[0]+k);

    }

    for(auto& it : res)
    {
        for(auto i : it.second)
        {
            answer[i] = regex_replace(answer[i], regex(it.first), db[it.first]);
        }
    }




    return answer;
}

