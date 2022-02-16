#include <string>
#include <vector>
#include <iostream>

using namespace std;

int maxValue = 0;
vector<int> lion(11,0);
vector<int> result(11,0);

bool is_sorted(vector<int>& lion)
{
    for(int i=10;i>=0;i--)
    {
        if(lion[i]>result[i])
            return true;
        else if(lion[i]<result[i])
            return false;
    }
}

void get_score(vector<int>& lion, vector<int>& apeach)
{
    int score = 0;
    for(int i=0;i<=10;i++)
    {
        if(lion[i]==0 && apeach[i]==0)
            continue;
        if(lion[i]>apeach[i])
            score+=10-i;
        else
            score+=i-10;
            
    }
    
    if(score>0 && score>=maxValue)
    {
        if(maxValue==score && !is_sorted(lion))
            return;
        
        maxValue = score;
        result = lion;
    }
}

void dfs(int idx, int remain, vector<int>& lion, vector<int>& apeach)
{
    if(idx==11 || remain==0)
    {
        lion[10]+=remain;
        get_score(lion, apeach);
        lion[10]-=remain;
        return;
    }
    
    if(remain>apeach[idx])
    {
        lion[idx]+=(apeach[idx]+1);
        dfs(idx+1, remain-apeach[idx]-1, lion, apeach);
        lion[idx]-=(apeach[idx]+1);
    }
    
    dfs(idx+1, remain, lion, apeach);
}

vector<int> solution(int n, vector<int> info) {
    
    dfs(0, n, lion, info);
    return (maxValue==0?vector<int>{-1}:result);
}
