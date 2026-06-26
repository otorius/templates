struct fenwick {
    int n; vector<ll> bit;

    fenwick() {}
    fenwick(int _n) : n(_n), bit(n + 1, 0) {}

    void init(int _n) {
        n = _n; bit.assign(n + 1, 0);
    }

    void add(int x, ll d) {
        for ( ; x <= n; x += (x & -x)) bit[x] += d;
    }

    ll get(int x) {
        ll ans = 0;
        for ( ; x; x -= (x & -x)) ans += bit[x];
        return ans;
    }

    ll query(int l, int r) {
        return get(r) - get(l - 1);
    }

    void clear() {
        fill(bit.begin(), bit.end(), 0);
    }
};
