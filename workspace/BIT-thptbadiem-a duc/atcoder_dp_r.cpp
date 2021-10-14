#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int add(int i, int j) {
	return (i+j)%mod;
}
int mul(int i, int j) {
	return int((long long) i * j % mod);
}

template<class T> struct Matrix {
	T **mat; int a, b;

	Matrix() : a(0), b(0) {}
	Matrix(int a_, int b_) : a(a_), b(b_) {
		int i, j;

		mat = new T*[a];
		for (i = 0; i < a; ++i) {
			mat[i] = new T[b];
			for (j = 0; j < b; ++j)
				mat[i][j] = 0;
		}
	}
	Matrix(const vector<vector<T>>& vt) {
		int i, j;

		*this = Matrix((int) vt.size(), (int) vt[0].size());
		for (i = 0; i < a; ++i)
			for (j = 0; j < b; ++j)
				mat[i][j] = vt[i][j];
	}
	Matrix operator*(const Matrix& m) {
		int i, j, k;

		assert(b == m.a);
		Matrix r(a, m.b);
		for (i = 0; i < a; ++i)
			for (j = 0; j < m.b; ++j)
				for (k = 0; k < b; ++k)
					r.mat[i][j] = add(r.mat[i][j],
						mul(mat[i][k], m.mat[k][j]));
		return r;
	}
	Matrix& operator*=(const Matrix& m) {
		return *this = (*this) * m;
	}
	friend Matrix power(Matrix m, long long p) {
		int i;

		assert(m.a == m.b);
		Matrix r(m.a, m.b);
		for (i = 0; i < m.a; ++i)
			r.mat[i][i] = 1;
		for ( ; p > 0; p >>= 1, m *= m)
			if (p & 1)
				r *= m;
		return r;
	}
};

int main() {
    int n; long long k;
    cin >> n >> k;
    vector<vector<int>> a(n+1,vector<int>(n+1));    
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            cin >> a[i][j];
        }
    }
    Matrix<int> matrix(a);
    matrix = power(matrix,k);
    int ans = 0;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            ans = (ans + matrix.mat[i][j])%mod;
        }
    }
    cout << ans;
    return 0;
}