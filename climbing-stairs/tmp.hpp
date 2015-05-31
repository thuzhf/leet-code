namespace zf {
 using ll = long long;
 using ull = unsigned long long;
}
namespace zf {
 template <class T>
 std::vector<std::vector<T> > matrix_multiply( const std::vector<std::vector<T> > &ml, const std::vector<std::vector<T> > &mr) {
  unsigned ml_row_n = ml.size();
  unsigned ml_col_n = ml[0].size();
  unsigned mr_row_n = mr.size();
  unsigned mr_col_n = mr[0].size();
  if (ml_col_n != mr_row_n) {
   throw std::invalid_argument( "The first matrix's column's dimension didn't match the second matrix's row's dimension." );
  } else if (0 == ml_row_n || 0 == ml_col_n || 0 == mr_row_n || 0 == mr_col_n) {
   throw std::invalid_argument( "Input matrix's dimensions should both be positive." );
  }
  unsigned ret_row_n = ml_row_n;
  unsigned ret_col_n = mr_col_n;
  unsigned inter_n = ml_col_n;
  std::vector<std::vector<T> > ret;
  T tmp;
  for (unsigned i = 0; i < ret_row_n; ++i) {
   std::vector<T> one_row;
   for (unsigned j = 0; j < ret_col_n; ++j) {
    tmp = 0;
    for (unsigned k = 0; k < inter_n; ++k) {
     tmp += ml[i][k] * mr[k][j];
    }
    one_row.push_back(tmp);
   }
   ret.push_back(one_row);
  }
  return ret;
 }
}
namespace zf {
 template <class T>
 std::vector<std::vector<T> > matrix_pow(const std::vector<std::vector<T> > &m, unsigned exp) {
  if (exp < 0) {
   throw std::invalid_argument( "The exponent should be nonnegative." );
  }
  using vvT_st = typename std::vector<std::vector<T> >::size_type;
  using vT_st = typename std::vector<T>::size_type;
  vvT_st order = m.size();
  vT_st order2 = m[0].size();
  if (order != order2) {
   throw std::invalid_argument( "The input matrix is not a square matrix." );
  }
  std::vector<std::vector<T> > ret;
  if (0 == exp) {
   for (vvT_st i = 0; i < order; ++i) {
    std::vector<T> tmp;
    for (vvT_st j = 0; j < order; ++j) {
     tmp.push_back(j == i ? 1 : 0);
    }
    ret.push_back(tmp);
   }
   return ret;
  }
  std::vector<bool> odd;
  bool tmp_odd;
  ret = m;
  for (unsigned i = exp; i > 1; i /= 2) {
   if (1 == i % 2) {
    tmp_odd = true;
   } else {
    tmp_odd = false;
   }
   odd.push_back(tmp_odd);
  }
  for (std::vector<bool>::size_type i = odd.size(); i-- != 0; ) {
   if (odd[i]) {
    ret = zf::matrix_multiply(zf::matrix_multiply(ret, ret), m);
   } else {
    ret = zf::matrix_multiply(ret, ret);
   }
  }
  return ret;
 }
}
namespace zf {
 template <class T>
 T fibonacci(unsigned n, T x1 = 1, T x2 = 1, T a = 1, T b = 1) {
  T ret = 0;
  if (0 == n) {
   return 0;
  } else if (1 == n) {
   return x1;
  } else if (2 == n) {
   return x2;
  }
  std::vector<std::vector<T> > m;
  std::vector<T> tmp;
  tmp.push_back(a);
  tmp.push_back(b);
  m.push_back(tmp);
  tmp.clear();
  tmp.push_back(1);
  tmp.push_back(0);
  m.push_back(tmp);
  tmp.clear();
  std::vector<std::vector<T> > init;
  init.push_back(std::vector<T>(1, x2));
  init.push_back(std::vector<T>(1, x1));
  std::vector<std::vector<T> > final_m = zf::matrix_pow(m, n - 2);
  ret = zf::matrix_multiply(final_m, init)[0][0];
  return ret;
 }
}
class Solution {
 public:
  int climbStairs(int n) {
   return zf::fibonacci(n, 1, 2);
  };
};
