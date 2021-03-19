#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>



using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    vector<vector<bool>> res(n+1, vector<bool>(n+1));
    vector<bool> visited(n+1);
    vector<int> dist(n+1);

    for(auto i : edge)
    {
        res[i[0]][i[1]]=true;
        res[i[1]][i[0]]=true;

    }

    queue<int> res2;
    for(int i=1;i<=n;i++)
    {
        if(res[1][i])
        {
            res2.push(i);
            visited[1]=true;
            visited[i]=true;
            dist[i]=1;
        }
    }

    while(!res2.empty())
    {
        auto temp = res2.front();
        res2.pop();

        for(int i=1;i<=n;i++)
        {
            if(res[temp][i] && !visited[i])
            {
                visited[i]=true;
                dist[i]=1+dist[temp];
                res2.push(i);
            }
        }


    }

    auto it = *max_element(dist.begin(), dist.end());

    answer = count(dist.begin(), dist.end(), it);




    return answer;
}

