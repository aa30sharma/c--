#include <iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<limits.h>
using namespace std;
class graph{
public:
  map<int,vector<pair<int,int>>>mp;
void add(int u,int v,int direction,int weight){
  mp[u].push_back({v,weight});
  if(direction==0){
    mp[v].push_back({u,weight});
  }
}
 void print(){
   for(auto x:mp){
     cout<<x.first<<"->";
     for(auto y:x.second){
       cout<<"("<<y.first<<","<<y.second<<"),";
     }
     cout<<endl;
   }
 }
void shortestpath(int src,int des){
  map<int,int>par;
  map<int,bool>visit;
  queue<int>q;
    par[src]=-1;
  visit[src]=true;
  q.push(src);
  while(!q.empty()){
    int top=q.front();
    q.pop();
    for(auto x:mp[top]){
      int nabiour=x.first;
      if(visit[nabiour]!=true){
        q.push(nabiour);
        visit[nabiour]=true;
        par[nabiour]=top;
      }
    }
  }

int node=des;
vector<int>path;
while(node!=-1){
  path.push_back(node);
  node=par[node];
  
}
for(int i=path.size()-1;i>=1;i--){
  cout<<path[i]<<"->";
}
}
map<int,bool>visit;

void topo(int src,stack<int>&st){
  visit[src]=true;
  for(auto x:mp[src]){
    int nabiour=x.first;
    if(!visit[nabiour]){
      topo(nabiour,st);
    }
  }
  st.push(src);
}
void shortpath(int des,stack<int>st,int n){
  vector<int>dis(n,INT_MAX);
  int top=st.top();
    st.pop();
  dis[top]=0;
  for(auto x:mp[top]){
    if(dis[top]+x.second<dis[x.first]){
          dis[x.first]=dis[top]+x.second;
        }
  }
  while(!st.empty()){
     top=st.top();
     st.pop();
    if(dis[top]!=INT_MAX){
      for(auto x:mp[top]){
        if(dis[top]+x.second<dis[x.first]){
          dis[x.first]=dis[top]+x.second;
        }
      }
    }
  }
  for(int i=0;i<dis.size();i++){
    cout<<dis[i]<<" ";
  }
}

};
int main() {
 graph g;
  g.add(1,2,1,5);
  g.add(1,4,1,2);
  g.add(2,3,1,5);
  g.add(3,6,1,7);
  g.add(4,5,1,1);
  g.add(5,6,1,6);
  g.add(1,7,1,3);
  g.add(7,6,1,1);
    g.print();
 // g.shortestpath(2,5);
  cout<<endl;
  stack<int>st;
  g.topo(1,st);
  g.shortpath(6,st,8);
  cout<<endl;
  while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
  }
}
