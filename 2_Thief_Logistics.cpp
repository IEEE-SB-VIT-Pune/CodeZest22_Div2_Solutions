/*
CodeZest22 Div2 Solutions
Question 2 - Thief Logistics

Problem Statement-
You are a thief who has broken into a jewellery store.

The store has N pieces of jewellery called Jewel 1 through N, and you have X boxes called Box 1 through X. 
Each Jewel j has a size of Sj and a value of Vj. Box j can contain a jewel whose size is of at most Zj. It cannot contain two or more jewels.

In the input you will be given Q queries. In each query, you are provided with two integers A and B, solve the following problem:
Out of the X boxes, B-A+1 boxes,i.e., Box A, A+1,..., B, have become unavailable. 
Find the maximum possible total value of a set of jewels that we can put into the remaining boxes simultaneously.
*/

#include <bits/stdc++.h>
using namespace std;
                
int main(){
    int n,x,q;
    cin>>n>>x>>q;
    vector<pair<int,int>> vec(n);
    for(int i=0;i<n;i++){
        int s,v;
        cin>>s>>v;
        vec.push_back(make_pair(v,s));
    }
    sort(vec.rbegin(),vec.rend());
    vector<int> box(x);
    for(int i=0;i<x;i++) 
    {
        cin>>box[i];
    }
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        multiset<int> ms;
        for(int i=0;i<x;i++)
        {
            if(i<a || i>b) 
            {
                ms.insert(box[i]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            auto itr = ms.lower_bound(vec[i].second);
            if(itr != ms.end()){
                ans+=vec[i].first;
                ms.erase(itr);
            }
        }
    

        cout<<ans<<"\n";
    }
    return 0;
}