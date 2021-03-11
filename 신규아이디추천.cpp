#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <regex>


using namespace std;

string solution(string new_id) {
    string answer = "";
    // first
    transform(new_id.begin(), new_id.end(), new_id.begin(), [](auto e)
              {
                  return isupper(e)?tolower(e):e;
              });
    //second
    string op="-_.";
    for(auto& i : new_id)
    {
        if(isdigit(i) || isalpha(i) || op.find(i)!=op.npos) // not matching char
        {
            answer+=i;
        }
    }
    // third
    // regex로 제거
    regex re("[.]+");
    answer = regex_replace(answer, re, ".");
    
    // four
    // first and back erase if equal to dot
    if(!answer.empty())
    {
        if(answer[0]=='.')
            answer.erase(answer.begin());
    }
    
    if(!answer.empty())
    {
        if(answer.back()=='.')
            answer.pop_back();
    }
    
    // fifth
    
    if(answer.empty())
        answer+="a";
    
    // six
    
    if(answer.size()>=16)
    {
        answer = answer.substr(0, 15);
        if(answer.back()=='.')
            answer.pop_back();
    }
    
    // last
    
    if(answer.size()<=2)
    {
        char a = answer.back();
        while(answer.size()!=3)
            answer+=a;
    }
    return answer;
}
