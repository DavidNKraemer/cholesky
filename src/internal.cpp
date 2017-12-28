#include <cstdlib>      // exit, EXIT_FAILURE
#include <iostream>     // cerr
#include <fstream>      // ofstream
#include "_internal_routines.h"

namespace ams562proj1 { 
  namespace internal {

    ////////////////////////////////////////////////
    // After calling this routine, y = alpha * x + y
    // Precondition: len(x), len(y) >= n
    ////////////////////////////////////////////////
    void axpy(const int n, const double alpha, const double *x, double *y)
    {
      for (int i = 0; i < n; i++)
        y[i] += alpha * x[i];
    }

    ////////////////////////////////////////////////
    // After calling this routine, y = alpha * y
    // Precondition: len(y) >= n
    ////////////////////////////////////////////////
    void scal(const int n, const double alpha, double *y)
    {
      for (int i = 0; i < n; i++)
        y[i] *= alpha;
    }

    ////////////////////////////////////////////////
    // After calling this routine, y = x
    // Precondition: len(x), len(y) >= n
    ////////////////////////////////////////////////
    void copy(const int n, const double *x, double *y)
    {
      for (int i = 0; i < n; i++)
        y[i] = x[i];
    }

    ////////////////////////////////////////////////
    // After calling this routine
    //      if cond == false,
    //          then, we print msg
    //          abort program
    ////////////////////////////////////////////////
    void myassert(bool cond, const std::string &msg)
    {
      if (!cond) {
        std::cerr << msg << std::endl;
        abort();
      }
    }

    ///////////////////////////////////////////////
    // After calling this routine
    //      write the data in x into filename
    // Precondition: len(x) >= n
    //////////////////////////////////////////////
    void write2txt1d(const std::string &filename, const int n, const double *x)
    {
      std::ofstream file {filename, std::ios::app};

      for (int i = 0; i < n; i++) {
        file << x[i] << ' ';
      }
    }
  } /* end internal */ 

} // end ams562proj1
