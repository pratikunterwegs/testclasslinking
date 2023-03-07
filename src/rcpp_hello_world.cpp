
// [[Rcpp::depends(RcppParallel)]]

#include <Rcpp.h>
#include <testclasslinking.h>

// [[Rcpp::export]]
Rcpp::IntegerVector get_numbers(const int &samples, const bool &multithreaded = false) {

    // make a class object
    testclasslinking::testclass object (samples, multithreaded);
    object.init();

    return Rcpp::wrap(object.value);
}

// [[Rcpp::export]]
Rcpp::IntegerVector get_numbers_vec(const int &samples) {

    return Rcpp::wrap(testclasslinking::get_numbers_v (samples));
}

// [[Rcpp::export]]
Rcpp::NumericVector get_numbers_func(const Rcpp::List &list) {
  return Rcpp::wrap(helpers::get_numbers_functional(list));
}
