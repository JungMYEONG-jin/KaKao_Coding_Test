#include <string>
#include <vector>

using namespace std;

bool visited[9];
int maxValue = 0;
void dfs(vector<vector<int>> dungeons, int k, int cnt)
{
    int len = dungeons.size();
    for(int i=0;i<len;i++)
    {
        if(!visited[i] && k>=dungeons[i][0])
        {
            visited[i] = true;
            dfs(dungeons, k-dungeons[i][1], cnt+1);
            visited[i] = false;
        }
    }
    
    maxValue = max(maxValue, cnt);
    
    
}



int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    dfs(dungeons, k, 0);
    answer = maxValue;
    return answer;
}
