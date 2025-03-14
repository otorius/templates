template <typename T> class matrix {
private:
    int n, m;
    vector<vector<T>> mat;
public:
    matrix(int _n, int _m);
    matrix(const matrix<T> &rhs);
    virtual ~matrix();

    matrix<T> &operator=(const matrix<T> &rhs);

    matrix<T> &operator+=(const matrix<T> &rhs);
    matrix<T> &operator-=(const matrix<T> &rhs);
    matrix<T> &operator*=(const matrix<T> &rhs);
    matrix<T> &operator/=(const matrix<T> &rhs);

    matrix<T> operator+(const matrix<T> &rhs);
    matrix<T> operator-(const matrix<T> &rhs);
    matrix<T> operator*(const matrix<T> &rhs);
    matrix<T> operator/(const matrix<T> &rhs);

    vector<T> operator*(const vector<T> &rhs);
    vector<T> diag_vec();

    T &operator()(const int &x, const int &y);
    const T &operator()(const int &x, const int &y);

    matrix<T> transpose();
    int get_rows() const;
    int get_cols() const;
}

template <typename T>
matrix<T>::matrix(int _n, int _m) {
    mat.resize(_n);
    for (int i = 0; i < _n; i++)
        mat[i].resize(_m, 0);
    n = _n; m = _m;
}

template <typename T>
matrix<T>::matrix(const matrix<T> rhs) {
    mat = rhs.mat;
    n = rhs.get_rows();
    m = rhs.get_cols();
}

template <typename T>
matrix<T>::~matrix(){}

template <typename T>
matrix<T> &matrix<T>::operator=(const matrix<T> &rhs) {
    if (&rhs == this) return this;
    int _n = rhs.get_rows();
    int _m = rhs.get_cols();
    mat.resize(_n);
    for (int i = 0; i < _n; i++)
        mat[i].resize(_m, 0);
    for (int i = 0; i < _n; i++)
        for (int j = 0; j < _m; j++)
            mat[i][j] = rhs(i, j);
    n = _n; m = _m;
}
