#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;


// 접두어 탐색은 트라이 알고리즘이 좋다하여 트라이 알고리즘 사용
// 하지만 다른 사용자들 풀이보니 맵만으로도 해결이 가능한것 같음..

struct Trie{

	bool terminal;
	Trie* next[20];

	Trie(): terminal(false)
	{
		memset(next, 0, sizeof(next));
	}

	~Trie(){
	
	// given phone number length is less or equal than 20
	for(int i=0;i<20;i++)
	{
		if(next[i])
			delete next[i];
	}

	}

	bool insert(string& key, int idx) // copy by reference to save memory
	{
		if(idx==key.size())
		{
			terminal = true;
			return true;
		}else
		{
			// not end of the number but terminal true then there is prefix!
			if(terminal)
				return false;
			
			int index = key[idx]-'0';
			if(next[index]==0)
				next[index] = new Trie();
			else if(next[index]!=0 && idx+1==key.size())
				return false;
						
		

			return next[index]->insert(key, idx+1);

		}


	}


};



bool solution(vector<string> phone_book) {
    bool answer = true;
    
    Trie* root = new Trie();
    int len = phone_book.size();
    
    for(int i=0;i<len;i++)
    {
        if(answer==false)
            continue;
        
        answer = root->insert(phone_book[i], 0);
        
    }
    return answer;
}






/* 해쉬맵으로 푼다면

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_map<string, int> hash_map;
    for(int i = 0; i < phone_book.size(); i++)
        hash_map[phone_book[i]] = 1;

    for(int i = 0; i < phone_book.size(); i++) {
        string phone_number = "";
        for(int j = 0; j < phone_book[i].size(); j++) {
            phone_number += phone_book[i][j];
            if(hash_map[phone_number] && phone_number != phone_book[i])
                answer = false;
        }
    }

    return answer;
}






















*/
