struct HLD {
    int n, tim = 0;
    vector<vector<int>> g;
    vector<int> par, dep, sz, hvy, head, pos, rev;

    HLD(int _n) : n(_n) {
        g.assign(n + 1, {}); par.assign(n + 1, -1); dep.assign(n + 1, 0); sz.assign(n + 1, 0);
        hvy.assign(n + 1, -1); head.assign(n + 1, 0); pos.assign(n + 1, 0); rev.assign(n + 1, 0); 
    }

    void add(int x, int y) {
        g[x].pb(y); g[y].pb(x);
    }

    int dfs_sz(int v, int p) {
        par[v] = p; sz[v] = 1; int mx = 0;
        for (int u : g[v]) {
            if (u == p) continue;
            dep[u] = dep[v] + 1; sz[v] += dfs_sz(u, v);
            if (sz[u] > mx) {
                mx = sz[u]; hvy[v] = u;
            }
        } return sz[v];
    }

    void dfs_hld(int v, int h) {
        head[v] = h; pos[v] = ++tim; rev[tim] = v;
        if (hvy[v] != -1) dfs_hld(hvy[v], h);
        for (int u : g[v]) {
            if (u == par[v] || u == hvy[v]) continue;
            dfs_hld(u, u);
        }
    }

    void init(int root = 1) {
        dfs_sz(root, 0); dfs_hld(root, root);
    }

    int lca(int x, int y) {
        while (head[x] != head[y]) {
            if (dep[head[x]] < dep[head[y]]) swap(x, y);
            x = par[head[x]];
        } return (dep[x] < dep[y] ? x : y);
    }

    template<class F>
    void query(int x, int y, F func) {
        while (head[x] != head[y]) {
            if (dep[head[x]] < dep[head[y]]) swap(x, y);
            func(pos[head[x]], pos[x]); x = par[head[x]];
        }

        if (dep[x] > dep[y]) swap(x, y);
        func(pos[x], pos[y]);
    }
};
