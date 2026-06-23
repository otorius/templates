struct fraction {
    ll num, den;
    fraction(ll n = 0, ll d = 1) {
        if (d < 0) n *= -1, d *= -1;
        ll g = __gcd(abs(n), abs(d));
        num = n / g; den = d / g;
    }

    void normalize() {
        if (den < 0) num *= -1, den *= -1;
        ll g = __gcd(abs(num), abs(den));
        num /= g; den /= g;
    }

    fraction operator+(const fraction& other) const {
        return fraction(num * other.den + other.num * den, den * other.den);
    }

    fraction operator-(const fraction& other) const {
        return fraction(num * other.den - other.num * den, den * other.den);
    }

    fraction operator*(const fraction& other) const {
        return fraction(num * other.num, den * other.den);
    }

    fraction operator/(const fraction& other) const {
        return fraction(num * other.den, den * other.num);
    }

    fraction& operator+=(const fraction& other) {
        *this = *this + other; return *this;
    }

    fraction& operator-=(const fraction& other) {
        *this = *this - other; return *this;
    }

    fraction& operator*=(const fraction& other) {
        *this = *this * other; return *this;
    }

    fraction& operator/=(const fraction& other) {
        *this = *this / other; return *this;
    }

    bool operator==(const fraction& other) const {
        return (num == other.num && den == other.den);
    }

    bool operator!=(const fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const fraction& other) const {
        return (num * other.den < den * other.num);
    }

    bool operator<=(const fraction& other) const {
        return (num * other.den <= den * other.num);
    }

    bool operator>(const fraction& other) const {
        return (num * other.den > den * other.num);
    }

    bool operator>=(const fraction& other) const {
        return (num * other.den >= den * other.num);
    }

    friend ostream& operator<<(ostream& os, const fraction& frac) {
        return os << frac.num << "/" << frac.den;
    }
};
