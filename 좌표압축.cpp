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
   int n;
   cin>>n;

   set<int> db;
   int num;
   vector<int> temp;
   for(int i=0;i<n;i++)
   {
      cin>>num;
      temp.push_back(num);
      db.insert(num);
   }
   map<int, int> ans;
   int cnt = 0;
   for(auto& it : db)
   {
      ans[it] = cnt++;
   }

   for(auto& it : temp)
      cout<<ans[it]<<" ";

   return 0;



   

    
}
