#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>


using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;

    // 추월 했다는 의미는 자신의 left와 swap 하는걸로
    // 어차피 1등은 부르지 않는다 했으므로 end point 체크라던지 안해도 될듯..
    map<string, int> playdb;
    map<int, string> rankdb;
    
    for(int i=0, len = players.size() ; i<len ; i++){
        playdb[players[i]] = i+1;
        rankdb[i+1] = players[i];
    }
    
    for(const auto& call : callings){
        int idx = playdb[call];
        string left = rankdb[idx-1];
        playdb[call] = idx-1;
        playdb[left] = idx;
        rankdb[idx-1] = call;
        rankdb[idx] = left;
    }
    
    
    for(const auto& it : rankdb){
        answer.push_back(it.second);
    }
    
    return answer;
}
