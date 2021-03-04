#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    // first take light weight people
    sort(people.begin(), people.end());
    
    int use = 0;
    
    deque<int> res;
    for(auto i : people)
        res.push_back(i);
    // 30 50 50 70
    // 30 70 50 50 ok?
    
    int cur=0;
    
    while(!res.empty())
    {
        cur = res.back();
        res.pop_back();
        if(!res.empty() && (cur+=res.front())<=limit)
        {
            res.pop_front();
        }
        use++;
    }
    
    
    
    return use;
}


/* 신박한 풀이




int left =0;
int right = people.size()-1;

while(left<=right)
{

	if(people[left]+people[right]<=limit)
		left++;

	use++;
	--right;

}

return use;



*/
