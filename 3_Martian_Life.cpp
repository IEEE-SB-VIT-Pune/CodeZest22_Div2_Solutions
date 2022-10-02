/*
CodeZest22 Div2 Solutions
Question 3 - Martian Life

Problem Statement-
It's 2050 !! and Elon Musk has successfully colonized Mars. 
However, due to lack of oxygen the colonies are in the form of enclosed glass domes.

There are N number of colonies (from 1 to N), and the inhabitants on Mars use glass tunnels as a medium of transport between two colonies. 
There are M numbers of such tunnels (from 1 to M).

However, any tunnel i acts as a one-way transport route from colony Pi to colony Qi and it takes Xi minutes to travel through. 
There can exist multiple tunnels between two colonies and hence, Pi = Qi is also possible.

You, as a Mars inhabitant, decided to tour through all the colonies; however, your tour will be considered valid if you manage to go through one or more tunnels and return back to the same colony from where you started your tour. 
So, you decide to start the tour from each colony one by one, thus, determine whether a tour is valid from each colony, and if it's valid, then print the minimum time required for the tour when you start from that colony.
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    int a,b,c;
    cin>>n>>m;
    vector<vector<pair<int,int>>> g(n,vector<pair<int,int>>(0));
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        a--;
        b--;
        g[a].push_back(make_pair(b,c));
        
    }
    for(int i=0;i<n;i++)
    {
        priority_queue<pair<int,int>> q;
        for(pair<int,int> node:g[i])
        {
            q.push(make_pair(-1*node.second,node.first));
        }
                   int flag=0;
        vector<int> used(n,0);
        while(q.size()!=0)
                   {
                       
                      pair<int,int> temp= q.top();
             q.pop();
                       if(temp.second==i)
                       {
                           cout<<temp.first*-1<<endl;
                           flag=1;
                           break;
                       }
            if(used[temp.second]==1)
            {
                continue;
            }
            used[temp.second]=1;
                      
                       for(pair<int,int> m:g[temp.second])
                       {
                           if(used[m.first]==1)
                           {
                               continue;
                           }
                           q.push(make_pair(temp.first-m.second,m.first));
                       }
                   }
                   if(!flag)
                   cout<<-1<<endl;
    }
    return 0;
}