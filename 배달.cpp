#include <iostream>
#include <vector>
#include <queue>


using namespace std;


vector<pair<int,int>> city[52];
int INF=10000001;

int min_distance[52];


bool visited[52];

int dijkstra(int start, int cost, int n, int k)
{
    int tot = n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({cost, start});
    while(!pq.empty())
    {

        auto t = pq.top();
        pq.pop();


        if(visited[t.second])
            continue;

        if(t.first>k)
            tot--;

        visited[t.second]=true;


        for(auto i : city[t.second])
        {
            int next = i.second;
            int cur_cost  = i.first;

            if(!visited[next] && min_distance[next]>cur_cost+t.first)
            {
                min_distance[next] =t.first+ cur_cost;
                pq.push({min_distance[next], next});
            }

        }



    }

    return tot;
}



int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    fill_n(min_distance, N+1, INF);



    for(auto& i : road)
    {
        city[i[0]].push_back({i[2], i[1]});
        city[i[1]].push_back({i[2], i[0]});
    }
    //min_distance[0]=0;
    min_distance[1]=0;
    answer = dijkstra(1, 0,N,K);
    return answer;
}

