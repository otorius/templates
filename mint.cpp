class mint {
public:
    ll val;
    static ll mod_exp(ll a, ll b) {
        ll res = 1;
        a = a % mod;
        while (b > 0) {
            if (b % 2 == 1)
                res = (res * a) % mod;
            b /= 2;
            a = (a * a) % mod;
        }
        return res;
    }

    static ll gcdExtended(ll a, ll b, ll *x, ll *y) {
        if (a == 0) {
            *x = 0, *y = 1;
            return b;
        }

        ll x1, y1;
        ll gcd = gcdExtended(b % a, a, &x1, &y1);
        *x = y1 - (b / a) * x1;
        *y = x1;
        return gcd;
    }

    static ll modInverse(ll a) {
        ll x, y;
        ll g = gcdExtended(a, mod, &x, &y);
        g++;
        ll res = (x % mod);
        if (res < 0)
            res += mod;
        return res;
    }

    mint() { val = 0; }

    mint(ll x) {
        val = x % mod;
        if (val < 0)
            val += mod;
    }
    mint &operator+=(const mint &other) {
        val += other.val;
        if (val >= mod)
            val -= mod;
        return (*this);
    }

    mint &operator-=(const mint &other) {
        val -= other.val;
        if (val < 0)
            val += mod;
        return (*this);
    }
    mint &operator*=(const mint &other) {
        val = (val * other.val) % mod;
        return (*this);
    }
    mint &operator/=(const mint &other) {
        val = (val * modInverse(other.val)) % mod;
        return (*this);
    }
    mint &operator=(const mint &other) {
        val = other.val;
        return (*this);
    }

    mint operator+(const mint &other) const { return mint(*this) += other; }
    mint operator-(const mint &other) const { return mint(*this) -= other; }
    mint operator*(const mint &other) const { return mint(*this) *= other; }
    mint operator/(const mint &other) const { return mint(*this) /= other; }
    bool operator==(const mint &other) const { return val == other.val; }
 
    mint operator++() {
        ++val;
        if (val == mod)
            val = 0;
        return (*this);
    }

    mint operator++(int) {
        val++;
        if (val == mod)
            val = 0;
        return mint(val - 1);
    }

    mint operator--() {
        --val;
        if (val == -1)
            val = mod - 1;
        return (*this);
    }

    mint operator--(int) {
        val--;
        if (val == -1)
            val = mod - 1;
        return mint(val + 1);
    }
 
    template <typename T>
    mint &operator^=(const T &other) {
        val = mod_exp(val, other);
        return (*this);
    }
    template <typename T>
    mint operator^(const T &other) const { return mint(*this) ^= other; }
 
    mint &operator^=(const mint &other) {
        val = mod_exp(val, other.val);
        return (*this);
    }
    mint operator^(const mint &other) const { return mint(*this) ^= other; }
 
    template <typename T>
    explicit operator T() { return (T)val; }
    template <typename T>
    friend mint operator+(T other, const mint &M) { return mint(other) + M; }
    template <typename T>
    friend mint operator-(T other, const mint &M) { return mint(other) - M; }
    template <typename T>
    friend mint operator*(T other, const mint &M) { return mint(other) * M; }
    template <typename T>
    friend mint operator/(T other, const mint &M) { return mint(other) / M; }
    template <typename T>
    friend mint operator^(T other, const mint &M) { return mint(other) ^ M; }
 
    friend std::ostream &operator<<(std::ostream &output, const mint &M) { return output << M.val; }
    friend std::istream &operator>>(std::istream &input, mint &M) {
        input >> M.val; M.val %= mod; return input;
    }
};
