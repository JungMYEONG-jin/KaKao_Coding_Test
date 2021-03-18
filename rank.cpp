#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    vector<vector<bool>> res(n+1, vector<bool>(n+1));

    for(auto i : results)
        res[i[0]][i[1]] = true;


    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
            {
                if(res[i][k] && res[j][i])
                    res[j][k]=true;
            }

    for(int i=1;i<=n;i++)
    {
        int count=0;
        for(int j=1;j<=n;j++)
        {
            if(res[i][j] || res[j][i])
                count++;
        }
        answer = count==n-1?answer+1:answer;
    }

}
