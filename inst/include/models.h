// Copyright 2023. See repository licence in LICENSE.md.
#ifndef INST_INCLUDE_MODELS_H_
#define INST_INCLUDE_MODELS_H_

// [[Rcpp::plugins(cpp14)]]
// [[Rcpp::depends(BH)]]

// clang-format off
#include <Rcpp.h>

#include <algorithm>
#include <iostream>
#include <vector>

#include <boost/numeric/odeint.hpp>
#include "ode.h"
// clang-format on

// add to namespace models
namespace models {

/* The rhs of x' = f(x) defined as a struct with an operator */
struct sir
{
    const float beta, gamma;
    sir( float beta, float gamma ) : beta( beta ), gamma( gamma ) {}

    void operator()( ode::state_type const& x , ode::state_type& dxdt , const double t ) 
    {
        dxdt[0] = -beta * x[0] * x[1];  // -beta*S*I
        dxdt[1] = beta * x[0] * x[1] - gamma * x[1];  // beta*S*I - gamma*I
        dxdt[2] = gamma * x[1];  // gamma*I
    }
};

}  // namespace models

#endif  // INST_INCLUDE_MODELS_H_
