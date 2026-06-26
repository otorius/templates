ll fact[maxN], ifact[maxN];
ll binpow(ll a, ll b) {
    a %= mod;
    if (!b) return 1;
    if (b & 1) return a * binpow(a, b - 1);
    return binpow(a * a, b >> 1);
}
ll inv(ll x) {
    return binpow(x, mod - 2);
}
void init() {
    fact[0] = 1;
    for (int i = 1; i < maxN; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    ifact[maxN - 1] = inv(fact[maxN - 1]);
    for (int i = maxN - 2; i >= 0; i--)
        ifact[i] = ifact[i + 1] * (i + 1) % mod;
}
ll nCk(ll n, ll k) {
    if (k > n || n < 0) return 0;
    return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}
