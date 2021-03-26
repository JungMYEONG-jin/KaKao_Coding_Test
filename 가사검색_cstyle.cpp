#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

struct Trie{
    map<int, int> db; // store length and its value
    bool terminal;
    Trie* next[26]; // only lower case
    Trie(): terminal(false)
    {
        memset(next, 0, sizeof(next));
    }
    
    ~Trie(){
        
        for(int i=0;i<26;i++)
        {
            if(next[i])
                delete next[i];
        }
        
        
    }
    
    bool insert(const char* key, int len)
    {
        if(*key=='\0')
        {
            return true;
        }else
        {
            int index = *key-'a';
            db[len]+=1;
            if(!next[index])
                next[index] = new Trie();
            
            return next[index]->insert(key+1,len);
            
        }
    }
    
    int find(const char* key, int len)
    {
        if(*key=='\0')
        {
            return terminal;
        }
        int res=0;
        int index = *key-'a';
        if(*key=='?')
            res+=db[len];
        else
        {
            if(!next[index])
                return 0;
            res = next[index]->find(key+1, len);
        }
        return res;
        
    }
};



vector<int> solution(vector<string> words, vector<string> queries) {
    int len = queries.size();
    vector<int> answer(len);
    
    
    Trie* forward = new Trie();
    Trie* backward = new Trie();
    
    int lenw = words.size();
    for(int i=0;i<lenw;i++)
    {
        string s = words[i];
        int temp_len = s.size();
        forward->insert(&s[0], temp_len);
        reverse(s.begin(), s.end());
        backward->insert(&s[0], temp_len);
        
    }
    
    
    for(int i=0;i<len;i++)
    {
        string s = queries[i];
        if(s[0]!='?')
        {
            answer[i] = forward->find(&s[0], s.size());
        }else{
            reverse(s.begin(), s.end());
            answer[i] = backward->find(&s[0], s.size());
        }
    }
    
    
    
    
    return answer;
}
