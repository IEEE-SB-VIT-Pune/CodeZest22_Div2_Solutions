/*
CodeZest22 Div2 Solutions
Question 1 - Pieces of Clothing

Problem Statement-
A tailor has abundant rectangular pieces of clothes, each having equal width and varying lengths (in metres). 
The minimum and maximum length noted is P metres and Q metres respectively, and the length of all other pieces lies between P and Q. 
(Note that the length of a piece can be a non-integer.)

The tailor is supposed to select a certain number of rectangular clothing pieces such that after joining them together, a Z kilometres long clothing piece could be obtained. 
You must assist him in determining the minimum and maximum number of pieces required to create a clothing item of length Z kilometres.

If no any set of pieces can collectively form a Z kilometres long clothing item, then print -1.
*/

#include <bits/stdc++.h>
using namespace std;
const int INF = 1<<29;
 
int main(){
    int p,q,z;
    cin >> p >> q >> z;
    z *= 1000;
 
    int ans_max = -1,ans_min = INF;
    int found = 0;
    for(int i = 1; i <= z; i++){ 
        if(p * i <= z && z <= q * i){
            ans_max = max(ans_max,i);
            ans_min = min(ans_min,i);
            found = 1;
        }
    }
    
    if(found) cout << ans_min << " " << ans_max << endl;
    else cout << -1 << endl;
 
    return 0;
}