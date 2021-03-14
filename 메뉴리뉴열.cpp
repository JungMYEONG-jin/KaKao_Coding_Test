#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <map>

using namespace std;

int arr[27];
map<string ,int> res;
vector<string> mem[27][21];

void combination(string str, int idx, string temp)
{
    if(temp.size()>1)
    {
        res[temp]++;
        arr[temp.size()] = max(arr[temp.size()], res[temp]);
        mem[temp.size()][res[temp]].push_back(temp);
    }
    
    for(int i=idx+1;i<str.size();i++)
    {
        temp+=str[i];
        combination(str, i, temp);
        temp.pop_back();
    }
}







vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    //string temp;
    for(auto& i : orders)
    {
        sort(i.begin(), i.end());
        combination(i, -1, "");
    }
   
    for(auto i : course)
    {
        if(arr[i]>1)
        {
            for(auto str : mem[i][arr[i]])
                answer.push_back(str);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
