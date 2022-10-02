/*
CodeZest22 Div2 Solutions
Question 4 - Beautiful Bracelet

Problem Statement-
Grandma wants to make a beautiful bracelet out of X number of beads. Bi and Qi represents the beauty and colour of the i-th bead, respectively. 
The colour of beads is represented by the range 1, 2, 3,…, R. Note that, Grandma has at least one bead of each colour.

Out of the X number of beads, Grandma has chosen R beads with distinct colours and made a bracelet using them. 
(Note that the order of beads doesn’t matter). By taking bitwise XOR of the beauty of chosen beads you can determine the beautifulness of the bracelet.

There are multiple possible ways to make a bracelet, your task is to find the beautifulness of the bracelet with the Y-th greatest beautifulness amongst all possible ways. 
(If there exist multiple ways of making bracelets having same value of beautifulness, then all of them are counted.)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
  ll x, r;
  cin>>x>>r; 
  vector<vector<ll> > V(r); 
  ll Y;
  cin>>Y;
  for(ll i=0; i<x; i++){
    ll color, beauty;
    cin>>color>>beauty;
    V[color-1].push_back(beauty);
  }

  sort(V.begin(),V.end(),[](vector<ll> v0,vector<ll> v1){return (v0).size()>(v1).size();});

  array<vector<ll>,2> P{{ {0}, {0} }}; 
  for(ll i=0; i<(ll)V.size(); i++){
    int flag=(P[0].size() > P[1].size());
    vector<ll> arr={};
    for(auto v:V[i])
        for(auto x:P[flag]) 
            arr.push_back(v^x);
    P[flag]=arr;
  }
 
  ll ans=0;
  vector<array<vector<ll>,2> > A = {{ P[0],P[1] }}; 
  for(ll B=59; B>=0; B--){
    vector<array<array<vector<ll>,2>,2> > arr={}; 
    ll cnt=0; 
    for(auto ab:A){
      array<array<vector<ll>,2>,2> nab = {{ {{ {},{} }},{{ {},{} }} }};
      for(ll i=0; i<2; i++)
          for(ll x:ab[i]) 
              nab[i][(x>>B)&1].push_back(x); 
      arr.push_back(nab);
      cnt += nab[0][0].size() * nab[1][1].size() + nab[0][1].size() * nab[1][0].size();
    }
    A={};
    
    if(cnt<Y){ 
      Y-=cnt;
      for(auto &[a,b]:arr){
          if((a[0]).size() and (b[0]).size())
              A.push_back({a[0],b[0]});
          if((a[1]).size() and (b[1]).size())
              A.push_back({a[1],b[1]});
      }
    } 
    else {   
      ans+=(ll)1<<B;
      for(auto &[a,b]:arr){
          if((a[0]).size() and (b[1]).size())
              A.push_back({a[0],b[1]});
          if((a[1]).size() and (b[0]).size())
              A.push_back({a[1],b[0]});
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}