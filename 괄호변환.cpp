#include <string>
#include <vector>
#include <stack>

using namespace std;

bool is_perfect(string p)
{
    stack<char> res;
    for(auto i : p)
    {
        if(i=='(')
            res.push(i);
        else
        {
            // 만약 right embrace면
            if(!res.empty() && res.top()=='(')
                res.pop();
        }

    }

    return res.size()==0; // 0이면 올바른 균형 문자열인것
}

bool is_balanced(string p)
{
    int left=0;
    for(auto i : p)
    {
        if(i=='(')
            left++;
        else
            left--;
    }
    return left==0;
}

string solution(string p) {
    string answer = "";
    if(p.empty())
        return answer;

    // 만약 처음부터 정답이거나 empty면
    if(is_perfect(p) || p.empty())
        return p;
    string u="";
    string v="";
    for(int i=2, len=p.size();i<=len;i+=2)// 균형을 유지해야 하므로 짝수개씩 늘려감
    {
        u = p.substr(0,i);
        if(is_balanced(u))
        {
            v = p.substr(i);
            break;
        }
    }



    if(is_perfect(u)) // u가 올바른 괄호문자열이면
    {
        answer+=u+solution(v);
    }else // 올바른 괄호문자열 아니면
    {
        answer+="("+solution(v)+")";
        if(!u.empty())
            u.erase(u.begin());
        if(!u.empty())
            u.pop_back();
        for(auto& i : u)
        {
            if(i=='(')
                i=')';
            else
                i='(';
        }
        answer+=u;
    }






    return answer;
}
