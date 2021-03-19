#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>


using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    if(lines.size()==1)
        return 1;
    
    vector<pair<int, int>> time;
    cout<<fixed;
    cout.precision(3);
    for(auto& i : lines)
    {
        vector<string> res;
    stringstream sstr(i);
        string temp;
        while(getline(sstr, temp, ' '))
            res.push_back(temp);
        auto k = res[1];
        double times=0;
        string test;
        double hour=3600.0;
        for(auto j : k)
        {
            if(j!=':')
                test+=j;
            else
            {
                times+=(double)(stod(test)*hour);
                test="";
                hour/=60;
            }
        }
        times+=stod(test);
        
        times*=1000;
        
        auto k2 = res[2];
        
        double times2 = stod(k2.substr(0, k2.size()-1));
        times2*=1000;
        
        time.push_back({times-times2+1, times});
        cout<<times<<endl;
        
    }
    
    
    for(auto& it : time)
        cout<<it.first<<" "<<it.second<<endl;
    int len = time.size();
    int mval=0;
    for(int i=0;i<len;i++)
    {
        int cnt=1;
        for(int j=i+1;j<len;j++)
        {
            if(time[i].first+1000>=time[j].first || time[i].second+1000>time[j].first)
                cnt++;
            
        }
        mval = max(mval, cnt);
    }
    
    answer =mval;
    
    return answer;
}
