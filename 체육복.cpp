#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    n-=lost.size(); // 일단 없는애들만큼 제거

    vector<int> real;
    for(auto i : reserve)
    {
        for(auto j : lost)
        {
            if(i==j)
            {
                real.push_back(i);
                break;
            }
        }
    }
    n+=real.size(); // 여유 있는데 도난당한애들은 자기들이 입을 수 있으니까 lost와 여유 겹치는수만큼 다시 더해줘야함.
    for(auto i : real)
    {
        auto it = find(reserve.begin(), reserve.end(), i);
        reserve.erase(it);
    }

    for(auto i : real)
    {
        auto it = find(lost.begin(), lost.end(), i);
        lost.erase(it);
    }
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end(), greater<int>());



    stack<int> temp;
    for(auto i : reserve)
        temp.push(i); // stack LIFO so 내림차순 정렬후 삽입



        while(!temp.empty())
        {

            for(int i =0, lens = lost.size();i<lens;i++)
            {
                if(temp.top()-1 ==lost[i] || temp.top()+1==lost[i])
                {
                    n++;
                    lost.erase(lost.begin()+i);
                    break;
                }

            }


            temp.pop();
        }






    cout<<n<<endl;


    return answer=n;
}





/* BEST CODE

#include <string>
#include <vector>

using namespace std;
int student[35];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for(int i : reserve) student[i] += 1;
    for(int i : lost) student[i] += -1;
    for(int i = 1; i <= n; i++) {
        if(student[i] == -1) {
            if(student[i-1] == 1) 
                student[i-1] = student[i] = 0;
            else if(student[i+1] == 1) 
                student[i] = student[i+1] = 0;
        }
    }
    for(int i  = 1; i <=n; i++)
        if(student[i] != -1) answer++;

    return answer;
}






















*/
