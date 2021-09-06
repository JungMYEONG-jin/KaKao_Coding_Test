#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int>> res(rows, vector<int>(columns));
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            res[i][j] = (i-1+1)*columns+1+j;
        }
    }

    
    
    
    
    
    for(auto& i : queries)
    {
        int x1 = i[0];
        int y1 = i[1];
        int x2 = i[2];
        int y2 = i[3];
        vector<vector<int>> temp = res;
        int mval = 1111111;
        for(int col = y1;col<y2;col++)
        {
            temp[x1-1][col] = res[x1-1][col-1];
            mval = min(mval, temp[x1-1][col]);
        }
        for(int row = x1;row<x2;row++)
        {
            temp[row][y2-1] = res[row-1][y2-1];
            mval = min(mval, temp[row][y2-1]);
        
        }
        for(int col = y2-2;col>=y1-1;col--)
        {
            temp[x2-1][col] = res[x2-1][col+1];
            mval = min(mval, temp[x2-1][col]);
        
        }
        for(int row = x2-2;row>=x1-1;row--)
        {
            temp[row][y1-1] = res[row+1][y1-1];
            mval = min(mval, temp[row][y1-1]);
        }
        
        answer.push_back(mval);
        res = temp;
        
        
    }
    
    
    
    
    return answer;
}
