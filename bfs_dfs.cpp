#include <vector>
#include <iostream>
#include <list>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;


int N, V, start;
int db[1001][1001];
bool visited[1001];

void dfs(int v)
{
   cout<<v<<" ";
   visited[v] = true;
   for(int i=1;i<=N;i++)
   {
      if(visited[i] || db[v][i]==0)
         continue;
      dfs(i);
   }
}

void bfs(int v)
{
   queue<int> q;
   q.push(v);
   visited[v] = false;
   while(!q.empty())
   {
      v = q.front();
      cout<<v<<" ";
      q.pop();
      for(int i=1;i<=N;i++)
      {
         // dfs 하고 시작하니까는 반대로
         if(!visited[i] || db[v][i]==0)
            continue;
         q.push(i);
         visited[i] = false;
      }
   }
}


int main()
{
	int x, y;
   cin>>N>>V>>start;
   for(int i=0;i<V;i++)
   {
      cin>>x>>y;
      db[x][y]=1;
      db[y][x]=1;
   }
   dfs(start);
   cout<<endl;
   bfs(start);
   return 0;
}
