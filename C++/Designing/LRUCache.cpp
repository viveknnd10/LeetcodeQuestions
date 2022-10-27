class LRUCache {
public:
    int size=0;
    unordered_map<int,list<pair<int,int>>::iterator> cache;
    list<pair<int,int>> dq;
    LRUCache(int capacity) 
    {
      size=capacity;   
    }
    
    int get(int key) 
    {
      if(cache.find(key)!=cache.end())
      {
        int val=cache[key]->second;
        dq.erase(cache[key]);
        dq.push_front({key,val});
        cache[key]=dq.begin();
        return val;
      }
      return -1;
    }
    
    void put(int key, int value) 
    {
      if(cache.find(key)==cache.end())
      {
        if(dq.size()==size)
        {
          int back=(dq.back()).first;
          dq.pop_back();
          cache.erase(back);
        }
      }
      else
      {
        dq.erase(cache[key]);
      }
      dq.push_front({key,value});
      cache[key]=dq.begin();
      return;
    }
};