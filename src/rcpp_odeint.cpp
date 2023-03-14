#include <Rcpp.h>
#include <testclasslinking.h>

// [[Rcpp::plugins(cpp14)]]
// [[Rcpp::depends(BH)]]

//' @title Some odeint function
//' @export
// [[Rcpp::export]]
Rcpp::List harmonic_oscillator(const Rcpp::NumericVector &init) {
    // get vector size
    ode::state_type x(init.size());
    //[ state_initialization
    x[0] = 1.0; // start at x=1.0, p=0.0
    x[1] = 0.0;
    //]

    //[ integrate_observ
    std::vector<ode::state_type> x_vec; // is a vector of double vectors
    std::vector<double> times;

    size_t steps = boost::numeric::odeint::integrate( ode::harmonic_oscillator ,
            x , 0.0 , 10.0 , 0.1 ,
            ode::push_back_state_and_time( x_vec , times ) );
    
    return Rcpp::List::create(
        Rcpp::Named("x") = Rcpp::wrap(x_vec),
        Rcpp::Named("time") = Rcpp::wrap(times)
    );
}

//' @title An SIR model
//' @export
// [[Rcpp::export]]
Rcpp::List sir(const Rcpp::NumericVector &init, const float &beta, const float &gamma) {
    // initial conditions from input
    ode::state_type x = Rcpp::as<std::vector<double> >(init);

    // create an sir struct
    models::sir this_model(beta, gamma);

    //[ integrate_observ
    std::vector<ode::state_type> x_vec; // is a vector of double vectors
    std::vector<double> times;

    // a controlled stepper for constant step sizes
    boost::numeric::odeint::runge_kutta4< ode::state_type > stepper;

    size_t steps = boost::numeric::odeint::integrate_const( 
            stepper,
            this_model ,
            x , 0.0 , 200.0 , 0.1 ,
            ode::push_back_state_and_time( x_vec , times ) );
    
    return Rcpp::List::create(
        Rcpp::Named("x") = Rcpp::wrap(x_vec),
        Rcpp::Named("time") = Rcpp::wrap(times)
    );
}
