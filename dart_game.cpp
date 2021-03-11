#include <string>
#include <iostream>




using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    int len = dartResult.size();
    bool triple=false;
    bool db = false;
    bool single = false;
    int multiple=1;
    int minus=1;
    int val=0;
    int cnt=0;
    for(int i=len-1;i>=0;i--)
    {
        
        
        if(dartResult[i]=='T')
        {
            triple=true;
        }else if(dartResult[i]=='D')
        {
            db = true;
        }else if(dartResult[i]=='S')
        {
            single= true;
        }else if(dartResult[i]=='#')
        {
            minus=-1;
        }else if(dartResult[i]=='*')
        {
            multiple*=2;
            val=2;
        }   
        else if(isdigit(dartResult[i]))
        { 
            
            int score=0;
            
            int j=i;
            while(isdigit(dartResult[j]))
            {
                j--;
            }
            j+=1;
            int num = stoi(dartResult.substr(j, i-j+1));
            
            i=j;
            
            
            //cout<<num<<endl;
            if(triple)
            {
                score = num*num*num*minus;
                if(val)
                {
                    score*=multiple;
                    val--;
                    cnt++;
                    if(val==0 || cnt%2==0)
                        multiple/=2;
                }
            }else if(db)
            {
                score = num*num*minus;
                if(val)
                {
                    score*=multiple;
                    val--;
                    cnt++;
                    if(val==0 || cnt%2==0)
                        multiple/=2;
                }
                
            }else if(single)
            {
                score = num*minus;
                if(val)
                {
                    score*=multiple;
                    val--;
                    cnt++;
                    if(val==0 || cnt%2==0)
                        multiple/=2;
                }
            }
            cout<<score<<endl;
            answer+=score;
            if(minus==-1)
                minus=1; // only applied first time
            triple = false;
            db=false;
            single=false;
            //val--;
            // init!
        }
        
        
        
    }
    
    
    return answer;
}
