#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> res;
    //int stage=1;
    //int num=1;
    
    int len = words.size();
    for(int i=0;i<len;i++)
    {
        if(res.count(words[i]) || i>0  && words[i-1].back()!=words[i][0])
        {
            answer.push_back(i%n+1);
            answer.push_back(i/n+1);
            return answer;
        }
        res.insert(words[i]);
        
    }
    
    

    return {0,0};
}
