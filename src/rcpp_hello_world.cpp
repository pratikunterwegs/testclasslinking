
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
