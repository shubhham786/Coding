#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;


//index of all charchter
void test(string s)
{
    unordered_map<char,vector<int>>map;
      
      for(int i=0;i<s.size();i++)
      {
          char ch=s[i];
          map[ch].push_back(i);
      }

        for(auto & key:map)
        {
            cout<<key.first<< "---->";

            vector<int>ans=key.second;

            for(int val:ans)
            {
                cout<<val<<" ";
            }

            cout<<endl;
        }
}