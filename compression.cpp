#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> res;
    int idx=1;
    for(auto i = 'A';i<='Z';i++)
        res[string(1,i)]=idx++;
    
    
    int len = msg.size();
    idx=1;
    for(int i=0;i<len;i++)
    {
        int j=i;
        string temp=msg.substr(i,1);
        while(res[temp])
        {
                j++;
                temp+=msg[j];
                
        }
        string test = temp;
        //cout<<temp<<endl;
        j--;
        i=j;
        temp.pop_back();
        if(res[temp])
        {
            answer.push_back(res[temp]);
            res[test]=26+idx;
            idx++;
        }else
        {
            
            res[temp]=26+idx;
            idx++;
        }
            
    }
    
    
    
    
    
    
    return answer;
}
