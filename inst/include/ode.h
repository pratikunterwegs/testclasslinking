// Copyright 2023 'epidemics' authors. See repository licence in LICENSE.md.
#ifndef INST_INCLUDE_ODE_H_
#define INST_INCLUDE_ODE_H_

// [[Rcpp::plugins(cpp14)]]
// [[Rcpp::depends(BH)]]

// clang-format off
#include <Rcpp.h>

#include <algorithm>
#include <iostream>
#include <vector>

#include <boost/numeric/odeint.hpp>
// clang-format on

// add to namespace ode
namespace ode {

//[ rhs_function
/* The type of container used to hold the state vector */
typedef std::vector< double > state_type;

const double gam = 0.15;

/* The rhs of x' = f(x) */
inline void harmonic_oscillator( const state_type &x , state_type &dxdt , const double /* t */ )
{
    dxdt[0] = x[1];
    dxdt[1] = -x[0] - gam*x[1];
}
//]

//[ integrate_observer
struct push_back_state_and_time
{
    std::vector< state_type >& m_states;
    std::vector< double >& m_times;

    push_back_state_and_time( std::vector< state_type > &states , std::vector< double > &times )
    : m_states( states ) , m_times( times ) { }

    void operator()( const state_type &x , double t )
    {
        m_states.push_back( x );
        m_times.push_back( t );
    }
};
//]

}  // namespace ode

#endif  // INST_INCLUDE_ODE_H_
