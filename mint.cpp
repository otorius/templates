class mint {
    long long val;
public:
    mint(const mint &);
    mint(long long n = 0);
    
    mint &operator=(const mint &);
    mint operator-(int tmp);
    mint &operator++();
    mint operator++(int tmp);
    mint &operator--();
    mint operator--(int tmp);
    
    friend bool operator==(const mint &a, const mint &b);
    friend bool operator!=(const mint &a, const mint &b);
    
    friend mint &operator+=(mint &a, const mint &b);
    friend mint &operator-=(mint &a, const mint &b);
    friend mint &operator*=(mint &a, const mint &b);
    friend mint &operator/=(mint &a, const mint &b);
    friend mint &operator^=(mint &a, const mint &b);
    
    friend mint operator+(const mint &a, const mint &b);
    friend mint operator-(const mint &a, const mint &b);
    friend mint operator*(const mint &a, const mint &b);
    friend mint operator/(const mint &a, const mint &b);
    friend mint operator^(const mint &a, const mint &b);
    
    friend mint &operator%=(mint &a, const long long int &mod);
    friend mint operator%(const mint &a, const long long int &mod);
    
    friend mint inv(mint &a);
    
    friend istream &operator>>(istream &, mint &);
    friend ostream &operator<<(ostream &, const mint &);
};

mint::mint(long long n) {
    val = n;
}
mint::mint(const mint &n) {
    val = n.val;
}

mint &mint::operator=(const mint &n) {
    val = n.val; return *this;
}
mint mint::operator-(int tmp) {
    mint cur = *this; cur.val *= -1; return cur;
}
mint &mint::operator++() {
    val = (val + 1) % mod; return *this;
}
mint mint::operator++(int tmp) {
    mint cur = *this; ++(*this); return cur;
}
mint &mint::operator--() {
    val = (val - 1 + mod) % mod; return *this;
}
mint mint::operator--(int tmp) {
    mint cur = *this; --(*this); return cur;
}

bool operator==(const mint &a, const mint &b) {
    return a.val == b.val;
}
bool operator!=(const mint &a, const mint &b) {
    return a.val != b.val;
}

mint inv(const mint &a) {
    mint ans = a; ans ^= (mod - 2); return ans;
}

mint &operator+=(mint &a, const mint &b) {
    a.val = (a.val + b.val) % mod; return a;
}
mint &operator-=(mint &a, const mint &b) {
    a.val = (a.val - b.val + mod) % mod; return a;
}
mint &operator*=(mint &a, const mint &b) {
    a.val = (a.val * b.val) % mod; return a;
}
mint &operator/=(mint &a, const mint &b) {
    a = (a * inv(b)) % mod; return a;
}
mint &operator^=(mint &a, const mint &b) {
    long long ans = 1, num = a.val, pwr = b.val;
    while (pwr) {
        if (pwr & 1) ans = (ans * num) % mod;
        num = (num * num) % mod; pwr >>= 1;
    } a.val = ans; return a;
}

mint operator+(const mint &a, const mint &b) {
    mint tmp = a; tmp += b; return tmp;
}
mint operator-(const mint &a, const mint &b) {
    mint tmp = a; tmp -= b; return tmp;
}
mint operator*(const mint &a, const mint &b) {
    mint tmp = a; tmp *= b; return tmp;
}
mint operator/(const mint &a, const mint &b) {
    mint tmp = a; tmp /= b; return tmp;
}
mint operator^(const mint &a, const mint &b) {
    mint tmp = a; tmp ^= b; return tmp;
}

mint &operator%=(mint &a, const long long int &mod) {
    a.val = (a.val % mod); return a;
}
mint operator%(const mint &a, const long long int &mod) {
    mint tmp = a; tmp %= mod; return tmp;
}

istream &operator>>(istream &in, mint &a) {
    in >> a.val; return in;
}
ostream &operator<<(ostream &out, const mint &a) {
    cout << a.val; return cout;
}
