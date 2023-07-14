#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>tree[200005];

int lift[200005][20];// lift[i][j]->node that is 2^j level above from node i

void binarylift(int src,int par){
    lift[src][0]=par; // node that is 2^0=1 level above from src should be its parent
    for(int i=1;i<20;i++){
        if(lift[src][i-1]!=-1){
            lift[src][i]=lift[lift[src][i-1]][i-1];
        }
        else{
            lift[src][i]=-1;
        }
    }
    // just call simple dfs
    for(auto child:tree[src]){
        if(child!=par){
            binarylift(child,src);
        }
    }
}

int query(int node,int level){
   for(int i=19;i>=0;i--){
      if(node==-1)return node;
    // 10101 ->check if ith bits is set and then jump above that level
      if(level&(1<<i)){
        node=lift[node][i];
      }
   }
   return node;
}


void solve(){
    int n,q;cin>>n>>q;
    for(int i=2;i<=n;i++){
        int a;cin>>a;
        tree[a].push_back(i);
    }
    binarylift(1,-1);
    while(q--){
        int node,k;cin>>node>>k;
        cout<<query(node,k)<<"\n";
    }
}


int32_t main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}