struct basis {
    static const int lg = 30;
    int b[lg];

    basis() {
        for (int i = 0; i < lg; i++) b[i] = 0;
    }

    basis &operator+=(int x) {
        for (int i = lg - 1; i >= 0; i--) {
            if ((x >> i) % 2 == 0) continue;
            if (!b[i]) { b[i] = x; return *this; }
            x ^= b[i];
        }

        return *this;
    } 

    basis &operator+=(const basis &other) {
        for (int i = 0; i < lg; i++)
            if (other.b[i]) *this += other.b[i];
        return *this;
    }
};
