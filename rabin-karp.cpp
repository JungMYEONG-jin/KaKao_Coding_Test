#include <iostream>
#include <string>


using namespace std;



void rabin(string& key, string& pattern)
{
    
    int len = key.size();
    int plen = pattern.size();
    int hash = 0, phash=0, power=1;
    
    
    for(int i=0;i<=len-plen;i++)
    {
        if(i==0)
        {
            for(int j=0;j<plen;j++)
            {
                hash+=key[plen-1-j]*power;
                phash+=pattern[plen-1-j]*power;
                if(j<plen-1)
                    power*=2;
            }
            
            
        }else
        {
            hash = 2*(hash-key[i-1]*power)+key[plen-1+i];
            
        }
        
        
        if(hash==phash)
        {
            bool flag = true;
            for(int j=0;j<plen;j++)
            {
                if(key[i+j]!=pattern[j])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                cout<<i+1<<"번째에서 찾음"<<endl;
            }
        }
        
    }
    
    
}

int main()
{
    
 string k = "abababcc";
 string pattern = "cc";
 
 rabin(k, pattern);
    
    
}
