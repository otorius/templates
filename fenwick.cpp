// #define fenint int
// #define fenint long long
// #define fenint unsigned long long

struct fenwick {
    fenint bit[maxN];
    
    void add(int x, fenint d) {
        for ( ; x < maxN; x += (x & -x)) bit[x] += d;
    }
    
    fenint get(int x) {
        fenint ans = 0;
        for ( ; x; x -= (x & -x)) ans += bit[x];
        return ans;
    }
    
    fenint query(int l, int r) {
        return get(r) - get(l - 1);
    }
    
    void init() {
        for (int i = 1; i <= maxN; i++) bit[i] = 0;
    }
};
