// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "../inst/include/testclasslinking.h"
#include <RcppEigen.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// get_numbers
Rcpp::IntegerVector get_numbers(const int& samples, const bool& multithreaded);
RcppExport SEXP _testclasslinking_get_numbers(SEXP samplesSEXP, SEXP multithreadedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const int& >::type samples(samplesSEXP);
    Rcpp::traits::input_parameter< const bool& >::type multithreaded(multithreadedSEXP);
    rcpp_result_gen = Rcpp::wrap(get_numbers(samples, multithreaded));
    return rcpp_result_gen;
END_RCPP
}
// get_numbers_vec
Rcpp::IntegerVector get_numbers_vec(const int& samples);
RcppExport SEXP _testclasslinking_get_numbers_vec(SEXP samplesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const int& >::type samples(samplesSEXP);
    rcpp_result_gen = Rcpp::wrap(get_numbers_vec(samples));
    return rcpp_result_gen;
END_RCPP
}
// get_numbers_func
Rcpp::NumericVector get_numbers_func(const Rcpp::List& list);
RcppExport SEXP _testclasslinking_get_numbers_func(SEXP listSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::List& >::type list(listSEXP);
    rcpp_result_gen = Rcpp::wrap(get_numbers_func(list));
    return rcpp_result_gen;
END_RCPP
}
// get_double_matrix
Eigen::MatrixXd get_double_matrix(const Rcpp::List& list);
RcppExport SEXP _testclasslinking_get_double_matrix(SEXP listSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::List& >::type list(listSEXP);
    rcpp_result_gen = Rcpp::wrap(get_double_matrix(list));
    return rcpp_result_gen;
END_RCPP
}

RcppExport SEXP run_testthat_tests(SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"_testclasslinking_get_numbers", (DL_FUNC) &_testclasslinking_get_numbers, 2},
    {"_testclasslinking_get_numbers_vec", (DL_FUNC) &_testclasslinking_get_numbers_vec, 1},
    {"_testclasslinking_get_numbers_func", (DL_FUNC) &_testclasslinking_get_numbers_func, 1},
    {"_testclasslinking_get_double_matrix", (DL_FUNC) &_testclasslinking_get_double_matrix, 1},
    {"run_testthat_tests", (DL_FUNC) &run_testthat_tests, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_testclasslinking(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
