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
        vector<int> temp;

        for(int col = y1-1;col<y2;col++)
            temp.push_back(res[x1-1][col]);

        for(int row = x1;row<x2;row++)
            temp.push_back(res[row][y2-1]);

        for(int col = y2-2;col>=y1-1;col--)
            temp.push_back(res[x2-1][col]);

        for(int row = x2-2;row>=x1;row--)
            temp.push_back(res[row][y1-1]);

        int last = temp.back();
        temp.pop_back(); // 맨뒤날리기
        temp.insert(temp.begin(), last); // 제일처음에 맨뒤 원소를 삽입 이러면 한칸씩 밀린 느낌

        answer.push_back(*min_element(temp.begin(), temp.end())); //최소값 넣음
        // 이제 기존 배열 업데이트가 필요함
        int idx = 0;
        for(int col = y1-1;col<y2;col++)
            res[x1-1][col] = temp[idx++];

        for(int row = x1;row<x2;row++)
            res[row][y2-1] = temp[idx++];

        for(int col = y2-2;col>=y1-1;col--)
            res[x2-1][col] = temp[idx++];

        for(int row = x2-2;row>=x1;row--)
            res[row][y1-1] = temp[idx++];


    }




    return answer;
}
