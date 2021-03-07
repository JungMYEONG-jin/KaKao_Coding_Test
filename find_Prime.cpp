#include <string>
#include <vector>
#include <cmath>
#include <set>


using namespace std;

set<int> res;
vector<int> visited(8,0);
string temp="";
bool is_Prime(int x)
{
    if(x<=1)
        return false;

    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0)
            return false;
    return true;
}








void find_all_solution(int idx, int limit, string number)
{
    if(idx==limit)
        return ;
    else
    {
        
        for(int i=0;i<limit;i++)
        {
            if(!visited[i])
            {
            visited[i]=1;
            temp += number[i];
            if(is_Prime(stoi(temp)))
                res.insert(stoi(temp));
            find_all_solution(idx+1, limit, number);
            temp.pop_back();
            visited[i]=0;
            }
        }
        
        
        
        
        
        
    }
}









int solution(string numbers) {
    int answer = 0;
    int len = numbers.size();
    find_all_solution(0, len, numbers);
    answer = res.size();
    return answer;
}
