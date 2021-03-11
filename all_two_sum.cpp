#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    
    int len = numbers.size();
    set<int> res;
    int val=0;
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            val = numbers[i]+numbers[j];
            if(i!=j && !res.count(val))
                res.insert(val);
        }
    }
    vector<int> answer(res.begin(), res.end());
    return answer;
}
