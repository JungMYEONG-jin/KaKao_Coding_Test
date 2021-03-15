#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool is_included(vector<int>& vec, int k)
{
    for(int i=0;i<vec.size();i++)
    {
        if((vec[i]&k) == vec[i])
            return false;
    }
    return true;
}


int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<int> arr;
    int col = relation[0].size();
    int row = relation.size();
    
    for(int i=1;i<(1<<col);i++)
    {
        set<string> res;
        for(int j=0;j<row;j++)
        {
            string temp="";
            for(int k=0;k<col;k++)
            {
                if((i&(1<<k)))
                    temp+=relation[j][k]+" ";
            }
                temp = temp.substr(0, temp.size()-1);
            res.insert(temp);
        }
        
        if(res.size()==row && is_included(arr, i))
            arr.push_back(i);
    }
    
    
    
    return arr.size();
}
