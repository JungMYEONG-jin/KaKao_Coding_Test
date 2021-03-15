#include <string>
#include <vector>

using namespace std;





vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    
    int l_row = arr1.size();
    int l_col = arr1[0].size();
    int r_row = arr2.size();
    int r_col = arr2[0].size();
    
    vector<vector<int>> answer(l_row, vector<int>(r_col));
    for(int i=0;i<l_row;i++)
    {
        
        for(int j=0;j<r_row;j++)
        {
            int sum=0;
            for(int k=0;k<r_col;k++)
            {
                    answer[i][k]+=arr1[i][j]*arr2[j][k];
            }
        }
    }
    
    
    
    
    
    
    
    
    
    
    return answer;
}
