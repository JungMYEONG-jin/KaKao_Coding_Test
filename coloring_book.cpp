#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int dir[2] ={1, -1};

int bfs(int x, int y,int m, int n, vector<vector<int>>& picture, vector<vector<bool>>& visited)
{
    int area=0;
    queue<pair<int, int>> res;
    int color = picture[x][y];
    
    visited[x][y]=true;
    
    res.push({x, y});
    
    while(!res.empty())
    {
        int a = res.front().first;
        int b = res.front().second;
        
        res.pop();
        area++;    
        for(int k=0;k<2;k++)
        {
            if(a-dir[k]<m && a-dir[k]>=0 && picture[a-dir[k]][b]==color && !visited[a-dir[k]][b])
            {
                res.push({a-dir[k], b});
                visited[a-dir[k]][b]=true;
            }
            if(b-dir[k]<n && b-dir[k]>=0 && picture[a][b-dir[k]]==color && !visited[a][b-dir[k]])
            {
                res.push({a, b-dir[k]});
                visited[a][b-dir[k]]=true;
            }
        }
    }
    return area;
    
}

int dfs(int x, int y, int m, int n, vector<vector<int>>& picture, vector<vector<bool>>& visited)
{
    
    
    int count=1;
    visited[x][y]=true;
    int color = picture[x][y];
    if(x!=0 && picture[x-1][y]==color && !visited[x-1][y]) count+=dfs(x-1, y, m, n, picture, visited);
    if(y!=0 &&  picture[x][y-1]==color&&!visited[x][y-1]) count+=dfs(x, y-1, m, n, picture, visited);
    if(x!=m-1 && picture[x+1][y]==color &&!visited[x+1][y]) count+=dfs(x+1, y, m, n, picture, visited);
    if(y!=n-1 && picture[x][y+1]==color &&!visited[x][y+1]) count+=dfs(x, y+1, m, n, picture, visited);
    
    return count;
}













vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int area = 0;
    int max_area = 0;
    
    
    vector<vector<bool>> visited(m, vector<bool>(n));
    // default false;
    
    vector<int> answer;
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(picture[i][j]!=0 && !visited[i][j])
            {
                answer.push_back(dfs(i, j, m, n, picture, visited));
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return {static_cast<int>(answer.size()), answer.back()};
}
