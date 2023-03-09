#ifndef INST_INCLUDE_CLASS_H_
#define INST_INCLUDE_CLASS_H_

// [[Rcpp::depends(RcppParallel)]]
// [[Rcpp::depends(RcppEigen)]]

#include <Rcpp.h>
#include <RcppParallel.h>
#include <RcppEigen.h>
#include <vector>
#include <functional>

namespace testclasslinking
{
class testclass
{
public:
    testclass(int size, bool multithreaded) : 
        value (size, 0),
        multithreaded (multithreaded)
    {}
    ~testclass() {}

    std::vector<int> value;
    bool multithreaded;

    // function
    void init ();
};

inline void testclass::init () {
    if (multithreaded) {
        tbb::parallel_for(
            tbb::blocked_range<unsigned>(0, value.size()),
            [&](const tbb::blocked_range<unsigned> &r) {
                for(unsigned i = r.begin(); i < r.end(); i++) {
                    value[i] = i;
                }
            }
        );
    } else {
        for (int i = 0; i < value.size(); i++)
        {
            value[i] = i;
        }   
    }
}

inline std::vector<int> get_numbers_v(const int &size) {
    std::vector<int> v (size, 0);
    for (int i = 0; i < size; i++)
    {
        v[i] = i;
    }
    return v;
}
} // namespace testclasslinking

/// @brief Helpers for functional usage.
namespace helpers {

inline std::vector<float> do_iterate(const Rcpp::List &list) {
  const int samples = list.length();
  
  // list must have matrix element named 'matrix'
  // convert this element to an Eigen matrix
  const Eigen::MatrixXd this_matrix = list["matrix"];
  // count rows
  const int nrow = this_matrix.rows();

  std::vector<float>tmp (samples + nrow, 0.f);
  
  for(int i = 0; i < samples; i++) {
    tmp[i] = static_cast<float>(i);
  }

  return tmp;
}

inline std::vector<float> invoke(
  std::function<std::vector<float>(const Rcpp::List)> func,
  const Rcpp::List &list
) {
  return func(list);
}

inline std::vector<float> get_numbers_functional(const Rcpp::List &list) {
  return invoke(&do_iterate, list);
}
} // namespace helpers

namespace matrixops {

inline Eigen::MatrixXd double_matrix(const Rcpp::List &list) {
  Eigen::Map<Eigen::MatrixXd> this_eigen_matrix(
    Rcpp::as<Eigen::Map<Eigen::MatrixXd> >(list["matrix"])
  );

  return this_eigen_matrix + this_eigen_matrix;
}

inline Eigen::MatrixXd invoke_matrixop(
  std::function<Eigen::MatrixXd(const Rcpp::List)> func,
  const Rcpp::List &list
) {
  return func(list);
}

inline void mod_matrix(const Rcpp::List &list) {
  list["matrix"] = invoke_matrixop(&double_matrix, list);
}
} // namespace matrixops

#endif  // INST_INCLUDE_CLASS_H_
