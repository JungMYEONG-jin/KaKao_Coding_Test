#include <string>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;




int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    if(*min_element(A.begin(), A.end())>*max_element(B.begin(), B.end()))
        return answer;
    sort(B.begin(), B.end());
    sort(A.begin(), A.end());
    int len = A.size();
    int idxA=0;
    int idxB=0;
    for(int i=0;i<len;i++)
    {
        if(A[idxA]>B[idxB])
        {
            idxB++;
        }else if(A[idxA]<B[idxB])
        {
            idxA++;
            idxB++;
            answer++;
        }else
            idxB++;
    }
    return answer;
}
