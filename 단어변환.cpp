#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int get_diff(string& a, string& b)
{
    int len = a.size();
    int num=0;
    for(int i=0;i<len;i++)
        if(a[i]!=b[i]) num++;
    return num;
}

vector<bool> visited(100, false);
int stage=100;
void dfs(string& begin, string& target, vector<string>& words, int cnt)
{
    for(int i=0;i<words.size();i++)
    {
        if(!visited[i] && get_diff(begin, words[i])==1)
        {
            if(target==words[i] && cnt+1<stage)
            {
                stage = cnt+1;
                return ;
            }
            visited[i]=true;
            dfs(words[i], target, words, cnt+1);
            visited[i]=false;
        }
    }

}





int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    if(find(words.begin(), words.end(), target)==words.end())
        return answer;
    
    
    
    dfs(begin, target, words, 0);
    
    return stage;
    
    
    }
