#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
vector<int> g[100005];
int a[100005];
long long ans = 0;

/* Compute square-free kernel */
int kernel(int x){
    int res = 1;
    for(int p = 2; p * p <= x; p++){
        int cnt = 0;
        while(x % p == 0){
            x /= p;
            cnt ^= 1;
        }
        if(cnt) res *= p;
    }
    if(x > 1) res *= x;
    return res;
}

/* DFS with DSU-on-tree merge */
map<int, long long>* dfs(int u){
    map<int, long long>* mp = new map<int, long long>();
    for(int v : g[u]){
        auto child = dfs(v);
        if(child->size() > mp->size()) swap(mp, child);

        // merge child into mp
        for(auto &p : *child){
            (*mp)[p.first] += p.second;
        }
        delete child;
    }

    // count kernel of this node
    int k = a[u];
    (*mp)[k]++;

    // beauty(u) = sum of C(freq[k], 2)
    long long beauty = 0;
    for(auto &p : *mp){
        long long f = p.second;
        beauty = (beauty + (f * (f - 1) / 2) % MOD) % MOD;
    }

    ans = (ans + beauty) % MOD;
    return mp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> par(n+1);
    for(int i=1;i<=n;i++) cin >> par[i];
    for(int i=2;i<=n;i++) g[par[i]].push_back(i);

    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        a[i] = kernel(x);
    }

    dfs(1);
    cout << ans % MOD;
}

