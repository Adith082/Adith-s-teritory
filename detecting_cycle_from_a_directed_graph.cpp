#include <bits/stdc++.h>
using namespace std;
#define sz 100
vector <int> adj[sz];
int vis[sz];
int indeg[sz];
queue <int> q;
void topo_init(int n){
   int i,j;
    for(i = 0;i<n;i++){
        if(indeg[i] == 0){
            q.push(i);
            vis[i] = 1;
        }
    }
    return;
}
int topo_sort(int n){
    int i,j,x;
    int cnt = 0;
    if(q.empty() == 1) return 1;
    while(!q.empty()){
        x = q.front();
        cnt++;
        q.pop();
        for(i = 0;i<adj[x].size();i++){
            if(!vis[adj[x][i]] && --indeg[adj[x][i]] == 0){
                vis[adj[x][i]] = 1;
                q.push(adj[x][i]);
            }
        }
    }
    if(cnt == n) return 0;
    else return 1;
}
int main()
{
    int p,q;
    int n,m;
    cin >> n >> m;
    int i,j;
    for(i = 0;i<m;i++){
        cin >> p >> q;
        adj[p].push_back(q);
        indeg[q]++;
    }
    topo_init(n);
    int res = topo_sort(n);
    if(res == 1) cout << "CYCLE DETECTED" << endl;
    else if(res == 0) cout << "NO CYCLE DETECTED" << endl;
    return 0;

}
