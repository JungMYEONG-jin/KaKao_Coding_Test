#include <string>
#include <vector>
#include <stack>
#include <numeric>
#include <algorithm>


using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.size();
    vector<int> res(len);
    auto trans = [](char ch){return 65 + (ch - 'A' + 25) % 26; };
    for(int i=0;i<len;i++)
    {
        if(name[i]>='A' && name[i]<='N')
            res[i]=name[i]-'A';
        else if(name[i]>='O' && name[i]<='Z')
        {

            int count=0;
            char ch = 'A';
            while(ch!=name[i])
            {
                ch = trans(ch);
                count++;
            }
            res[i] = count;
        }   
    }


    int idx=0;

    while(true)
    {
        answer+=res[idx];
        res[idx]=0;
        if(accumulate(res.begin(), res.end(), 0)==0) // 모두 돌았다면 
            break;
        int left=1, right=1;

        while(res[idx-left<=0?idx-left+len:idx-left]==0)
            left++; // A가 왼쪽에 있는만큼 ++
        while(res[idx+right>=len?idx+right-len:idx+right]==0)
            right++;
        if(right>left)
        {
            answer+=left; // left만큼 더해주고
            idx-=left;
            if(idx<0)
                idx+=len;
        }else
        {
            answer+=right;
            idx+=right;
        }
    }




    return answer;
}
