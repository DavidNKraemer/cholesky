#include "_internal_routines.h"
#include "_chol.h"
#include <cmath>
#include <iostream>
#include <fstream>

namespace ams562proj1 {

  using namespace internal;

  ////////////////////////////////////////////
  // After calling this function
  //          then A = tran(R)*R,
  //          R stores the upper decomp
  ///////////////////////////////////////////
  void chol(const matrix_t &A, matrix_t &R)
  {
    // Implementations needed
    // hints:

    //  [1] copy half of A into R
    //  [2] based on the algorithm, you should have two for-loops
    //      (a) inner one requires a subroutine
    //      (b) outer one requires a subroutine

    double factor;

    /* initializing R */
    for (int i = 0; i < A.size; i++) {

      // copy the upper triangle entries of A into R
      // you sort of have to squint at the pointers in the copy call in order to
      // see why this is copying the upper triangular entries
      copy(A.size - i, &(A.data[i][i]), &(R.data[i][i]));
    }

    /* cholesky factorization */
    // aka: more fun with pointers!
    // I'm using the pseudocode from Trefethan's Numerical Linear Algebra as a
    // guide

    // loop through rows
    for (int k = 0; k < R.size; k++) {
      // loop through upper triangular entries of a given row
      for (int j = k + 1; j < R.size; j++) { 
        factor = -1. * R.data[k][j] / R.data[k][k];

        // modify the upper triangulars of each column at a given k
        // R_{j,j:m} = R_{j,j:m} - R_{k,j:m} R_{kj} / R_{kk}
        axpy(R.size - j, factor, &(R.data[k][j]), &(R.data[j][j]));
      }

      // R_{k, k:m} = R_{k,k:m} / sqrt(R_{kk})
      scal(R.size - k, 1./std::sqrt(R.data[k][k]), &(R.data[k][k]));
    }
  }

  ///////////////////////////////////////////
  // After calling this function, there
  // should be text file that contains
  // the data of matrix A
  // using write2txt1d
  //////////////////////////////////////////
  void write2txt(std::string &filename, const matrix_t &A)
  {
    for (int i = 0; i < A.size; i++)
      write2txt1d(filename, A.size, A.data[i]); // this is inefficient, but hey
  }

  ///////////////////////////////////////////
  // After calling this function, A should
  // contains the data from text file
  // directly implement here
  //////////////////////////////////////////
  void readtxt(const std::string &filename, matrix_t &A)
  {
    // TODO: check preconditions... eh, it works
    std::ifstream file {filename};
    for (int i = 0; i < A.size; i++) {
      for (int j = 0; j < A.size; j++)
        file >> A.data[i][j];
    }
  }

} // end ams562proj1
