#ifndef INST_INCLUDE_CLASS_H_
#define INST_INCLUDE_CLASS_H_

// [[Rcpp::depends(RcppParallel)]]

#include <Rcpp.h>
#include <RcppParallel.h>
#include <vector>

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

#endif  // INST_INCLUDE_CLASS_H_