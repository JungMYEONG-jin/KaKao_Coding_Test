#include <string>
#include <vector>
#include <algorithm>

int key_size;
int lock_size;


using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    
    
    auto rotate = [](vector<vector<int>>& key)
    {
        int len = key.size();
        vector<vector<int>> res(len, vector<int>(len));
       for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++)
            {
                res[i][j] = key[len-j-1][i];
            }
        }
        return res;
    };
    
    
    
    key_size = key.size();
    lock_size = lock.size();
    int board_size = lock_size+2*(key_size-1);
    vector<vector<int>> board(board_size, vector<int>(board_size));
    
    // paint lock on the board
    
    for(int i=key_size-1;i<=board_size-key_size;i++)
    {
        for(int j=key_size-1;j<=board_size-key_size;j++)
            board[i][j] = lock[i-key_size+1][j-key_size+1];
    }
    

    
    
    auto unlock = [board_size](vector<vector<int>>& key, vector<vector<int>> board, int x, int y)
    {
      
        for(int i=x;i<x+key_size;i++)
        {
            for(int j=y;j<y+key_size;j++)
            {
                board[i][j]+=key[i-x][j-y];
            }
        }
        
        for(int i=key_size-1;i<=board_size-key_size;i++)
        {
            for(int j= key_size-1;j<=board_size-key_size;j++)
                if(board[i][j]!=1)
                    return false;
        }
        return true;
    };
    
    
    
    
    
    
    
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<=board_size-key_size;j++)
        {
            for(int k=0;k<=board_size-key_size;k++)
            {
                if(unlock(key, board, j,k))
                    return true;
            }
        }
        key = rotate(key);
    }
    

    return answer;
}
