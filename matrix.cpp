class matrix {
private:
    int n, m;
    vector<vector<int>> mat;
public:
    matrix(int _n, int _m);
    matrix(const matrix &rhs);

    matrix operator=(const matrix &rhs);

    matrix &operator+=(const matrix &rhs);
    matrix &operator-=(const matrix &rhs);
    matrix &operator*=(const matrix &rhs);

    matrix operator+(const matrix &rhs);
    matrix operator-(const matrix &rhs);
    matrix operator*(const matrix &rhs);

    matrix operator+(const int &rhs);
    matrix operator-(const int &rhs);
    matrix operator*(const int &rhs);
    matrix operator/(const int &rhs);
    matrix operator^(int &rhs);

    matrix &operator^=(int &rhs);
    vector<int> operator*(const vector<int> &rhs);

    int &operator()(const int &_n, const int &_m);
    const int &operator(const int &_n, const int &_m) const;

    int getrows() const;
    int getcols() const;
};

matrix::matrix(int _n, int _m) {
    mat.resize(_n);
    for (int i = 0; i < _n; i++)
        mat[i].resize(_m, 0);
    n = _n; m = _m;
}

matrix::matrix(const matrix &rhs) {
    mat = rhs.mat;
    n = rhs.getrows();
    m = rhs.getcols();
}

matrix::operator=(const matrix &rhs) {
    int _n = rhs.getrows();
    int _m = rhs.getcols();
    mat.resize(_n);
    for (int i = 0; i < _n; i++) {
        mat[i].resize(_m);
        for (int j = 0; j < _m; j++)
            mat[i][j] = rhs(i, j);
    } n = _n; m = _m;
    return *this;
}

matrix::operator+=(const matrix &rhs) {
    int _n = rhs.getrows();
    int _m = rhs.getcols();
    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _m; j++) {
            (mat[i][j] += rhs(i, j)) %= mod;
        }
    } return *this;
}

matrix::operator-=(const matrix &rhs) {
    int _n = rhs.getrows();
    int _m = rhs.getcols();
    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _m; j++) {
            (mat[i][j] -= rhs(i, j)) %= mod;
        }
    } return *this;
}

matrix::operator*=(const matrix &rhs) {
    int _n = rhs.getrows();
    int _m = rhs.getcols();
    matrix mult(_n, _m);

    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _m; j++) {
            for (int k = 0; k < _n; k++) {
                (mult(i, j) += this -> mat[i][j] * rhs(i, j) % mod) %= mod; 
            }
        }
    } (*this) = mult;
    return *this;
}

matrix::operator^=(int &rhs) {
    int _n = rhs.getrows();
    int _m = rhs.getcols();
    matrix pwr(_n, _m);
    for (int i = 0; i < _n; i++)
        pwr(i, i) = 1;
    while (rhs) {
        if (rhs & 1)
            pwr *= (*this);
        (*this) *= (*this);
    } (*this) = pwr; rhs >>= 1;
    return *this;
}
