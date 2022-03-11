#include<bits/stdc++.h>
using namespace std;
class Trie {
public:
    typedef struct trieNode
    {
      vector<struct trieNode *> children{26,NULL};
      bool isEnd=false;
    }trieNode;
    trieNode *root;
    Trie() 
    {
      root=new trieNode();
    }
  
    void insert(string word) 
    {
      trieNode *temp=root;
      for(auto i:word)
      {
        if(temp->children[i-'a']==NULL)
          temp->children[i-'a']=new trieNode();
        temp=temp->children[i-'a'];
      }
      temp->isEnd=true;
      return;
    }
    bool search(string word) 
    {
      trieNode *temp=root;
      for(auto i:word)
      {
        if(temp->children[i-'a']==NULL)
          return false;
        temp=temp->children[i-'a'];
      }
      return temp->isEnd;
    }
    
    bool startsWith(string prefix) 
    {
      trieNode *temp=root;
      if(search(prefix))
        return true;
      for(auto i:prefix)
      {
        if(temp->children[i-'a']==NULL)
          return false;
        temp=temp->children[i-'a'];
      }
      return true; 
    }
};

int main()
{
    Trie t;
    t.insert("apple");
    t.insert("app");
    t.insert("appl");
    t.insert("apples");
    t.insert("grapes");
    cout<<t.startsWith("app")<<endl;
    cout<<"test"<<t.search("grapes")<<endl;
    return 0;
}