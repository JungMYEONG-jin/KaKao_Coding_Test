#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    int len  = timetable.size();    
    vector<int> times(len);
    
    for(int i=0;i<len;i++)
    {
        
        int hour = stoi(timetable[i].substr(0,2));
        int minute = stoi(timetable[i].substr(3));
        
        times[i] = 60*hour+minute;
        
        
    }
    
    sort(times.begin(), times.end());
    
    int first = 540;
    int idx=0;
    int pass=m;
    for(int i=0;i<n;i++)
    {
        pass=m;
        for(int j=idx;j<len;j++)
        {
            if(times[j]<=first)
            {
                idx++;
                pass--;
                if(pass==0)
                    break;
            }
        }
        
        if(i+1==n)
            break;
        
        first+=t;
        
    }
    
    if(pass)
    {
        int hour = first/60;
        int minute = first%60;
        
        if(hour==0)
            answer+="00:";
        else if(hour<10)
            answer+="0"+to_string(hour)+":";
        else
            answer+=to_string(hour)+":";
        
        
        if(minute==0)
            answer+="00";
        else if(minute<10)
            answer+="0"+to_string(minute);
        else
            answer+=to_string(minute);
        
        
    }else
    {
        int time = times[idx-1]-1;
        int hour = time/60;
        int minute = time%60;
        
        if(hour==0)
            answer+="00:";
        else if(hour<10)
            answer+="0"+to_string(hour)+":";
        else
            answer+=to_string(hour)+":";
        
        
        if(minute==0)
            answer+="00";
        else if(minute<10)
            answer+="0"+to_string(minute);
        else
            answer+=to_string(minute);
        
    }
    
    
    
    
    
    
    
    
    return answer;
}
