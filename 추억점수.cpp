#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> db;
    for(int i=0, len = name.size() ; i<len ;i++){
        db[name[i]] = yearning[i];
    }
    for(const auto& it : photo){
        int score = 0;
        for(const auto& people : it){
            if(db.find(people) != db.end()){
                score += db[people];
            }
        }
        answer.push_back(score);
    }
    return answer;
}
