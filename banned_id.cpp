#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <set>


using namespace std;

set<string> res;

int ulen;
int blen;

bool visited[8];






bool comp(const string& left, const string& right)
{

    int len = left.size();
    int len2 = right.size();
    if(len!=len2)
        return false;
    for(int i=0;i<len;i++)
    {

        if(right[i]=='*')
            continue;
        else if(left[i]!=right[i])
            return false;


    }
    return true;




}






void recursive(vector<string>& uid, vector<string>& bid, int idx, string temp)
{
    if(blen==idx)
    {
        sort(temp.begin(), temp.end());
        res.insert(temp);
        return ;
    }


    string ban = bid[idx];





    for(int i=0;i<ulen;i++)
    {

        string user = uid[i];


        if(visited[i])
            continue;

        bool flag = true;


        if(!comp(user, ban))
            flag = false;


        if(flag)
        {
            visited[i] = true;

            recursive(uid, bid, idx+1, temp+to_string(i));

            visited[i] = false;
        }

    }


}



int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 1;
    ulen = user_id.size();
    blen = banned_id.size();
    string temp="";
    recursive(user_id, banned_id, 0, temp);

    return res.size();

}
