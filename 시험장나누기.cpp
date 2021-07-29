#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int bin_search(int& team, vector<int>& num, vector<vector<int>>& link, int cur, int mid)
{
    if(num[cur]>mid)
        return -1;
    if(link[cur][0]==-1 && link[cur][1]==-1)
        return num[cur];
    int w_left = 0, w_right=0;
    
    bool left = false;
    bool right = false;
    
    if(link[cur][0]!=-1)
    {
        left = true;
        w_left = bin_search(team, num, link, link[cur][0], mid);
        if(w_left==-1)
        {
            return -1;
        }
        if(w_left+num[cur]>mid)
        {
            team--;
            if(team<1)
                return -1;
            left = false;
            w_left=0;
        }
    }
    
    if(link[cur][1]!=-1)
    {
        right=true;
        w_right = bin_search(team, num, link, link[cur][1], mid);
        if(w_right==-1)
            return -1;
        if(w_right+num[cur]>mid)
        {
            team--;
            if(team<1)
                return -1;
            right=false;
            w_right=0;
        }
    }
    
    if(left && right)
    {
        int w = w_left+w_right+num[cur];
        if(w<=mid)
            return w;
        else
        {
            team--;
            if(team<1)
                return -1;
            if(w_left<w_right)
                return w_left+num[cur];
            else
                return w_right+num[cur];
        }
    }else
        return w_left+w_right+num[cur];
    
}



int solution(int k, vector<int> num, vector<vector<int>> links) {
    int answer = 0;
    unordered_set<int> res;
    int sum=0;
    for(int i=0, len = num.size();i<len;i++)
    {
        res.insert(i);
        sum+=num[i];
    }
    
    for(auto& it : links)
    {
        if(it[0]!=-1)
        {
            auto it2 = res.find(it[0]);
            if(it2!=res.end())
                res.erase(it2);
        }
        
        if(it[1]!=-1)
        {
            auto it2 = res.find(it[1]);
            if(it2!=res.end())
                res.erase(it2);
        }
        
        if(res.size()==1)
            break;
    }
    
    int s = 1;
    int e = sum;
    int root = *res.begin();
    while(s<=e)
    {
        int mid = (s+e)>>1;
        int team = k;
        if(bin_search(team, num, links, root, mid)!=-1)
            e = mid-1;
        else
            s = mid+1;
    }
    
    answer = s;
    
    return answer;
}
