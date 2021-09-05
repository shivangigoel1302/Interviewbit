#include<list>
unordered_map<int,int>m;
int cap;
list<int>l;
LRUCache::LRUCache(int capacity) {
   cap = capacity;
   m.clear();
   l.clear();
}

int LRUCache::get(int key) {
   if(m.find(key) != m.end()){
       auto it = find(l.begin(),l.end(),key);
       l.erase(it);
       l.push_back(key);
       return m[key];
   }
   return -1;
}

void LRUCache::set(int key, int value) {
    if(m.find(key) != m.end()){
       auto it = find(l.begin(),l.end(),key);
       l.erase(it);
       l.push_back(key);
       m[key] = value;
       return;
    }
    if(m.size() >= cap){
        int x = l.front();
        l.pop_front();
        m.erase(x);
        l.push_back(key);
        m[key] = value;
        return;
    }
    l.push_back(key);
    m[key] = value;
}
