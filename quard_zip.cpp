#include <string>
#include <vector>

using namespace std;



void quard(int x, int y, vector<vector<int>>& arr, int len, vector<int>& ans)
{
    
    bool one = true, zero=true;
    
    for(int i=x;i<x+len;i++)
    {
        for(int j=y;j<y+len;j++)
        {
            
            
            if(arr[i][j]==0)
                one=false;
            else if(arr[i][j]==1)
                zero=false;
        }
    }
    
    if(zero)
    {
        ans[0]++;
        return ;
    }
    
    if(one)
    {
        ans[1]++;
        return ;
    }
    
    quard(x, y, arr, len/2, ans);
    quard(x, y+len/2, arr, len/2, ans);
    quard(x+len/2, y, arr, len/2, ans);
    quard(x+len/2, y+len/2, arr, len/2, ans);
    
    
    
}









vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2,0);
    
    int len = arr.size();
    
    
    quard(0,0,arr,len,answer);    
    
    
    
    
    
    return answer;
}
