#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    map<string, set<string>> db; // id and user's ban id
    set<pair<string, string>> banned;
    map<string, int> user_banned_policy_db;
    for(auto id : id_list)
        db[id] = {};    


    for(auto info : report)
    {
        int idx = info.find(' ');
        string left = info.substr(0, idx);
        string right = info.substr(idx+1);

        if(banned.find({left, right})==banned.end())
        {
            db[left].insert(right); // dup ok
            user_banned_policy_db[right]+=1;
            banned.insert({left, right});

        }



    }

    for(string id : id_list)
    {
        int cnt = 0;
        for(string banned_id : db[id]) // id가 신고한 사람들
        {
            if(user_banned_policy_db[banned_id]>=k)
            {
                cnt++;
            }
        }
        answer.push_back(cnt);
    }





    return answer;
}
