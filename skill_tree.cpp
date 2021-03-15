#include <string>
#include <vector>
#include <regex>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(auto& i : skill_trees)
    {
        //string temp="";
        for(auto& j : i)
        {
            if(skill.find(j)==skill.npos)
                j=' ';
        }
        i=regex_replace(i, regex(" "),"");
    }
    
    for(auto& i : skill_trees)
    {
        int idx=0;
        bool flag = true;
        for(auto j : i)
        {
            if(j!=skill[idx])
            {
                flag = false;
                break;
            }
            
            idx++;
            
        }
        if(flag)
            answer++;
    }
    
    
    
    
    
    return answer;
}
