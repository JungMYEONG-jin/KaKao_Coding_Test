#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    
    vector<string> answer;
    
    vector<pair<long, long>> temp;
    
    long minX=10000000001;
    long maxX=-10000000001;
    long minY=10000000001;
    long maxY=-10000000001;
    int len = line.size();
    
    for(int i=0;i<len-1;i++)
    {
        long a = line[i][0];
        long b = line[i][1];
        long e = line[i][2];
        for(int j=i+1;j<len;j++)
        {
            long c = line[j][0];
            long d = line[j][1];
            long f = line[j][2];
            
            long underX = a*d-b*c;
            long upperX = b*f-e*d;
            
            long underY = underX;
            long upperY = e*c -a*f;
            
            
            if(underX!=0)
            {
                double solX = upperX/(underX+0.0);
                double solY = upperY/(underY+0.0);
                
                if(solX==ceil(solX) && solY==ceil(solY))
                {
                    temp.push_back({static_cast<long>(solX), static_cast<long>(solY)});
                    
                    minX = min(minX, static_cast<long>(solX));
                    maxX = max(maxX, static_cast<long>(solX));
                    minY = min(minY, static_cast<long>(solY));
                    maxY = max(maxY, static_cast<long>(solY));
                    
                }
                
            }
            
        }
    }
    int col = maxX-minX+1;
    int row = maxY-minY+1;
   
    string str(col,'.');
    answer.assign(row, str);
    
    for(auto pos : temp)
    {
        int x = pos.first-minX;
        int y = maxY-pos.second;
        
        answer[y][x] = '*';
    }
    
    
    
    return answer;

}
