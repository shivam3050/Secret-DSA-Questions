
#include <bits/stdc++.h>

using namespace std;

int main() {
    
  tuple<char, char, int> edges[5] = {
        {'S', 'P', 1},
        {'S', 'X', 10},
        {'P', 'Y', 1},   
        {'Y', 'X', 1},
        {'X', 'Z', 1}
  };

  map<char,vector<pair<int,char>>>G;
  map<char,int>initials;
  
  map<char,int>visited;

  for (auto & [u, v, w]: edges) {
    G[u].push_back({w,v});
    initials[u] = 500;
    initials[v] = 500;
  }
  initials['S'] = 0;
  

  for (auto & [u,childs]: G) {
      
    sort(childs.begin(), childs.end(), [](pair < int, char > & a, pair < int, char > & b) {
      return a.first < b.first;
    });

  }

  cout << "Now applying dijkshtra" << endl;
  
  // first select starting node then put all update each child of this node 
  // as you update i_th child of this node, push it in priority_queue, and
  // priority_queue should be based on value of child node and not on weight
  // once you update all the childs of this node , mark this node as visited,
  // never visit again this node in future
  
  priority_queue < pair < int, char > , vector < pair < int, char >> , greater < pair < int, char >>> q;
  
  for (auto & v : G['S']) {
    initials[v.second] = min(initials['S'] + v.first, initials[v.second]);
    q.push({ initials[v.second],v.second });
  }
  
  visited['S'] = 1;

  while (!q.empty()) {
    auto u = q.top();
    q.pop();
    if (!visited.contains(u.second)) {
      for (auto & child: G[u.second]) {
        if (!visited.contains(child.second)) {
          initials[child.second] = min(initials[u.second] + child.first, initials[child.second]);
          q.push({initials[child.second],child.second});
        }
      }
      visited[u.second] = 1;
    }

  }


  for (auto &[u,value]: initials) {

    if (value != 500) cout << u << " : " << value << endl;
    
  }

}
