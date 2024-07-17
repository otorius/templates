class big_int {
    vector<int> val;
public:
    big_int(string &);
    big_int(big_int &);
    big_int(const big_int &);
    big_int(unsigned long long n = 0);
    
    friend void div2(big_int &);
    friend bool is_null(const big_int &);
    friend int length(const big_int &);
    
    big_int &operator=(const big_int &);
    big_int &operator++();
    big_int operator++(int tmp);
    big_int &operator--();
    big_int operator--(int tmp);
    
    friend bool operator>(const big_int &a, const big_int &b);
    friend bool operator<(const big_int &a, const big_int &b);
    friend bool operator==(const big_int &a, const big_int &b);
    friend bool operator!=(const big_int &a, const big_int &b);
    friend bool operator>=(const big_int &a, const big_int &b);
    friend bool operator<=(const big_int &a, const big_int &b);
    
    friend big_int &operator+=(big_int &a, const big_int &b);
    friend big_int &operator-=(big_int &a, const big_int &b);
    friend big_int &operator*=(big_int &a, const big_int &b);
    friend big_int &operator/=(big_int &a, const big_int &b);
    friend big_int &operator%=(big_int &a, const big_int &b);
    friend big_int &operator^=(big_int &a, const big_int &b);
    
    
    friend big_int operator+(const big_int &a, const big_int &b);
    friend big_int operator-(const big_int &a, const big_int &b);
    friend big_int operator*(const big_int &a, const big_int &b);
    friend big_int operator/(const big_int &a, const big_int &b);
    friend big_int operator%(const big_int &a, const big_int &b);
    friend big_int operator^(const big_int &a, const big_int &b);
    
    friend istream &operator>>(istream &, big_int &);
    friend ostream &operator<<(ostream &, const big_int &);
    
    friend big_int sqrt(const big_int &a);
};

big_int::big_int(string &s) {
    for (int i = s.size() - 1; i >= 0; i--) val.pb(s[i] - '0');
}
big_int::big_int(unsigned long long n) {
    do {
        val.pb(n % 10); n /= 10;
    } while (n);
}
big_int::big_int(big_int &a) {
    val = a.val;
}
big_int::big_int(const big_int &a) {
    val = a.val;
}

void div2(big_int &a) {
    int carry = 0;
    for (int i = a.val.size() - 1; i >= 0; i--) {
        int tmp = a.val[i] / 2 + carry;
        carry = a.val[i] % 2 * 5;
        a.val[i] = tmp;
    }
}
bool is_null(const big_int &a) {
    return (a.val.size() == 1 && a.val[0] == 0);
}
int length(const big_int &a) {
    return a.val.size();
}

big_int &big_int::operator=(const big_int &a) {
    val = a.val;
    return *this;
}
big_int &big_int::operator++() {
    int n = val.size(), i;
    for (i = 0; i < n && val[i] == 9; i++) val[i] = 0;
    if (i == n) val.push_back(1);
    else val[i]++;
    return *this;
}
big_int big_int::operator++(int tmp) {
    big_int tem = *this;
    ++(*this);
    return tem;
}
big_int &big_int::operator--() {
    int n = val.size(), i;
    for (i = 0; i < n && val[i] == 0; i++) val[i] = 9;
    val[i]--;
    if (n > 1 && val.back() == 0) val.pop_back();
    return *this;
}
big_int big_int::operator--(int tmp) {
    big_int tem = *this;
    --(*this);
    return tem;
}

bool operator==(const big_int &a, const big_int &b) {
    return a.val == b.val;
}
bool operator!=(const big_int &a, const big_int &b) {
    return !(a == b);
}
bool operator>(const big_int &a, const big_int &b) {
    int n = length(a), m = length(b);
    if (n != m) return n > m;
    for (int i = n - 1; i >= 0; i--)
        if (a.val[i] != b.val[i]) return a.val[i] > b.val[i];
    return false;
}
bool operator<(const big_int &a, const big_int &b) {
    return b > a;
}
bool operator>=(const big_int &a, const big_int &b) {
    return !(a < b);
}
bool operator<=(const big_int &a, const big_int &b) {
    return !(a > b);
}

big_int &operator+=(big_int &a, const big_int &b) {
    int n = length(a), m = length(b);
    if (n < m) {
        int x = n - m;
        while (x--) a.val.push_back(0);
    } n = length(a);
    int tmp, carry = 0;
    for (int i = 0; i < n; i++) {
        if (i < m) tmp = a.val[i] + b.val[i] + carry;
        else tmp = a.val[i] + carry;
        carry = tmp / 10;
        a.val[i] = tmp % 10;
    } if (carry) a.val.push_back(carry);
    return a;
}
big_int &operator-=(big_int &a, const big_int &b) {
    int n = length(a), m = length(b);
    int tmp, carry = 0;
    for (int i = 0; i < n; i++) {
        if (i < m) tmp = a.val[i] - b.val[i] + carry;
        else tmp = a.val[i] + carry;
        if (tmp < 0) {
            tmp += 10; carry = -1;
        } else carry = 0;
        a.val[i] = tmp;
    } while (n > 1 && a.val.back() == 0) {
        n--; a.val.pop_back();
    } return a;
}
big_int &operator*=(big_int &a, const big_int &b) {
    if (is_null(a) || is_null(b)) {
        a = big_int(); return a;
    } int n = length(a), m = length(b);
    vector<int> v(n + m, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            v[i + j] += a.val[i] * b.val[j];
    n += m;
    a.val.resize(n);
    int tmp, carry = 0;
    for (int i = 0; i < n; i++) {
        tmp = v[i] + carry;
        carry = tmp / 10;
        a.val[i] = tmp % 10;
    } while (n > 1 && a.val.back() == 0) {
        n--; a.val.pop_back();
    } return a;
}
big_int &operator/=(big_int &a, const big_int &b) {
    if (a < b) {
        a = big_int();
        return a;
    } if (a == b) {
        a = big_int(1);
        return a;
    } int n = length(a), i, j, sz = 0;
    vector<int> v(n, 0);
    big_int tmp;
    for (i = n - 1; tmp * 10 + a.val[i] < b; i--)
        tmp = tmp * 10 + a.val[i];
    for ( ; i >= 0; i--) {
        tmp = tmp * 10 + a.val[i];
        for (j = 9; j * b > tmp; j--);
        tmp -= j * b; v[sz++] = j;
    } for (i = 0; i < sz; i++)
        a.val[i] = v[sz - i - 1];
    a.val.resize(sz);
    return a;
}
big_int &operator%=(big_int &a, const big_int &b) {
    if (a < b) return a;
    if (a == b) {
        a = big_int();
        return a;
    } int n = length(a), i, j;
    big_int tmp;
    for (i = n - 1; tmp * 10 + a.val[i] < b; i--)
        tmp = tmp * 10 + a.val[i];
    for ( ; i >= 0; i--) {
        tmp = tmp * 10 + a.val[i];
        for (j = 9; j * b > tmp; j--);
        tmp -= j * b;
    } a = tmp;
    return a;
}
big_int &operator^=(big_int &a, const big_int &b) {
    big_int tmp = b, base(a);
    a = 1;
    while (!is_null(tmp)) {
        if (tmp.val[0] & 1) a *= base;
        base *= base;
        div2(tmp);
    } return a;
}

big_int operator+(const big_int &a, const big_int &b) {
    big_int tmp = a;
    tmp += b;
    return tmp;
}
big_int operator-(const big_int &a, const big_int &b) {
    big_int tmp = a;
    tmp -= b;
    return tmp;
}
big_int operator*(const big_int &a, const big_int &b) {
    big_int tmp = a;
    tmp *= b;
    return tmp;
}
big_int operator/(const big_int &a, const big_int &b) {
    big_int tmp = a;
    tmp /= b;
    return tmp;
}
big_int operator%(const big_int &a, const big_int &b) {
    big_int tmp = a;
    tmp %= b;
    return tmp;
}
big_int operator^(const big_int &a, const big_int &b) {
    big_int tmp = a;
    tmp ^= b;
    return tmp;
}

istream &operator>>(istream &in, big_int &a) {
    string s; in >> s;
    int n = s.size(); a.val.resize(n);
    for (int i = n - 1; i >= 0; i--)
        a.val[n - i - 1] = s[i] - '0';
    return in;
}
ostream &operator<<(ostream &out, const big_int &a) {
    for (int i = a.val.size() - 1; i >= 0; i--) cout << a.val[i];
    return cout;
}

big_int sqrt(big_int &a) {
    big_int l(1), r(a), ans, m, tmp;
    while (l <= r) {
        m += l;
        m += r;
        div2(m);
        tmp = m * m;
        if (tmp <= a) {
            ans = m;
            ++m; l = m;
        } else {
            --m; r = m;
        } m = big_int();
    } return ans;
}
