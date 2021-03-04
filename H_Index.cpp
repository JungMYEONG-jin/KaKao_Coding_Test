#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    //int answer = 0;
    // 정렬후 중간값이  h index 같은데?
    sort(citations.begin(), citations.end());
    int h=0;
    int len = citations.size();
    int i=0;

    while(true)
    {

        int left= count_if(citations.begin(), citations.end(),[i](auto e){return e<=i;});
        int right = count_if(citations.begin(), citations.end(), [i](auto e){return e>=i;});
        if(left<=i && right>=i)
            h=i;
        else if(right<i)
            break;
        i++;
    }

    return h;
}

/*
신박한 방법 이진 탐색

bool go(vector<int>& vec, int mid)
{
int res=0;
for(int i=0;i<vec.size();i++)
{
  if(vec[i]>=mid)
    res++;
}
return res>=mid;

}

int solution(vector<int> citations) {
    //int answer = 0;
    int left =0;
    int right=10000;
    int h=0;

    while(true)
    {

        int mid = (left+right)/2;
        if(go(c, mid))
        {
        h=mid;
        left = mid+1;
        }else
          right = mid-1;
    }

    return h;
}








*/
