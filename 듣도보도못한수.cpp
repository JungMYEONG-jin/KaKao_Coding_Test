#include <iostream>
#include <bitset>
#include <string>
#include <regex>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;



int main()
{
   ios_base::sync_with_stdio(false);
   int n, m;
   cin>>n>>m;

   map<string ,int> db;
   string name;
   for(int i=0;i<n;i++)
   {
      cin>>name;
      db[name]++;
   }

   for(int i=0;i<m;i++)
   {
      cin>>name;
      db[name]++;
   }

   set<string> res;
   for(auto& it : db)
   {
      if(it.second>1)
         res.insert(it.first);
   }

   for(auto& it : res)
      cout<<it<<endl;

    
}
