#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
#include <sstream>


using namespace std;

string converse_melody(string& m, map<string, char>& info)
{
    string new_m="";
    for(int i=0;i<m.size();i++)
    {
        if(m[i]=='C' || m[i]=='D' || m[i]=='F' || m[i]=='G' || m[i]=='A')
        {
            if(m[i+1]=='#')
            {
                new_m+=info[m.substr(i,2)];
                i++;
            }else
                new_m+=info[string(1, m[i])];
        }else
            new_m+=info[string(1, m[i])];
    }
    
    return new_m;
    
}





string solution(string m, vector<string> musicinfos) {
    string answer = "";
    
    map<string, char> info;
    info["C"]='C'; info["C#"]='Q'; info["D"]='D';info["D#"]='R'; info["E"]='E';info["F"]='F';info["F#"]='S';
    info["G"]='G'; info["G#"]='P'; info["A"]='A'; info["A#"]='O'; info["B"]='B';
    
    
    
    
    vector<vector<string>> music;
    vector<pair<int, string>> temp_ans;
    for(auto& i : musicinfos)
    {
        stringstream sstr(i);
        string temp;
        vector<string> res;
        while(getline(sstr, temp,','))
            res.push_back(temp);
        
        music.push_back(res);
    }
    
    
    string new_m= converse_melody(m, info);
    
    
    
    
    for(auto& i : music)
    {
        auto it = i[0].find(':');
        
        int lh = stoi(i[0].substr(0, it));
        int lm = stoi(i[0].substr(it+1));
        
        it = i[1].find(':');
        
        int rh = stoi(i[1].substr(0, it));
        int rm = stoi(i[1].substr(it+1));
        
        rh-=lh;
        rm-=lm;
        if(rm<0 && rh>0)
        {
            rh-=1;
            rm+=60;
        }
        int len  = rh*60+rm;
        
    string new_mm=converse_melody(i[3], info);
        
        string test="";
        cout<<new_m<<" "<<new_mm<<endl;
        int len3 = new_mm.size();
        for(int j=0;j<len;j++)
        {
            test+=new_mm[j%len3];
       
                if(test.find(new_m)!=test.npos)
                {
                    temp_ans.push_back({len, i[2]});
                    break;
                }
            
        }
        
        
        
    }
    
    
    if(temp_ans.empty())
        return "(None)";
    
    
    stable_sort(temp_ans.begin(), temp_ans.end(), [](auto e, auto k){return e.first>k.first;});
    
    
    return temp_ans[0].second; 
}
