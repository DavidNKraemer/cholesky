#include "_matrix_t.h"
#include "_internal_routines.h"
#include "_chol.h"
#include <iostream>
#include <iomanip>
#include <string>

#ifdef ABS
#undef ABS
#endif
#define ABS(x) (((x)>0.0)?(x):-(x))

// idea borrowed from Wenbin Lu
const std::string PASS = "\033[1;32m PASS\033[0m\n";
const std::string FAIL = "\033[1;31m FAIL\033[0m\n";


using namespace ams562proj1;
void print_matrix_t(const matrix_t &A);


//
// YOU SHOULD NOT CHANGE ANYTHING IN THE TESTING
// PROGRAM, OTHERWISE THE TESTING MAY GO WRONG!
//

// main function

int main() {
  
  /* quick tests of internals */

  double x[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  double y[10];
  const double alpha = 5.0;
  internal::scal(10, alpha, x);
  internal::copy(10, x, y);
  internal::axpy(10, alpha, x, y);

  internal::myassert(true, "Test");

  std::string str {""};
  str += "hello!";

  std::cout << str << std::endl;

  for (int i = 0; i < 10; i++)
    std::cout << y[i] << std::endl;

  /* quick tests of reading/writing matrices */

  matrix_t A;
  A.size = 3;
  A.data = new double*[A.size];
  for (int i = 0; i < A.size; i++) {
    A.data[i] = new double[A.size];
    for (int j = 0; j < A.size; j++)
      A.data[i][j] = (i * j) % A.size;
  }

  print_matrix_t(A);

  std::cout << std::endl;

  std::string fname {"test.txt"};

  write2txt(fname, A);

  matrix_t B;
  B.size = 3;
  B.data = new double*[B.size];
  for (int i = 0; i < B.size; i++)
    B.data[i] = new double[B.size];

  readtxt(fname, B);

  print_matrix_t(B);

  std::cout << std::endl;
  /* quick test of cholesky */

  matrix_t C, R;
  C.size = 3;
  R.size = 3;
  C.data = new double*[C.size];
  R.data = new double*[R.size];
  for (int i = 0; i < C.size; i++) {
    C.data[i] = new double[C.size];
    R.data[i] = new double[R.size];
  }

  readtxt("cholesky.text", C);

  print_matrix_t(C);

  chol(C, R);

  std::cout << std::endl;
  print_matrix_t(R);


  return 0;
}

void print_matrix_t(const matrix_t &A) {
 for (int i = 0; i < A.size; i++) {
    for (int j = 0; j < A.size; j++)
      std::cout << A.data[i][j] << " ";
    std::cout << std::endl;
  }
}
