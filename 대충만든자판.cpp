#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;

    map<char, int> db;

    for(const auto& key : keymap){
        for(int i=0, len = key.size() ; i<len ; i++){
            if(db[key[i]] == 0){
                db[key[i]] = i+1;
            }else{
                db[key[i]] = min(i+1, db[key[i]]);
            }
        }
    }

    for(const auto& target : targets){
        int score = 0;
        bool isValid = true;
        for(int i = 0, len = target.length() ; i<len ; i++){
            if(db[target[i]] == 0)
            {
                isValid = false;
                break;
            }
            score += db[target[i]];
        }
        if(isValid){
            answer.push_back(score);
        }else{
            answer.push_back(-1);
        }
    }

    return answer;
}
