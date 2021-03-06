/**
 * \file classicKalman.h
 * \brief Add Comment Here
 *
 * \date Jun 5, 2011
 * \author alexander
 */

#ifndef CLASSICKALMAN_H_
#define CLASSICKALMAN_H_

#ifndef ASSERTS
#define ASSERTS
#endif

#include "global.h"

#include <vector>
#include "matrix.h"
#include "function.h"
namespace corecvs {

using std::vector;
/**
 *  TODO: Could be nice to make this template.
 **/


class ClassicKalman
{
public:
    /**
     *  _f is an evolution function
     *
     **/
    ClassicKalman(
            FunctionArgs *_f,
            FunctionArgs *_h,
            const Matrix &_Q,
            const Matrix &_R,
            const Matrix &_P,
            const Vector &_x
    ) :
        stateDim(_x.size()),
        measureDim(_h->outputs),
        f(_f),
        h(_h),
        x(_x),
        xPredicted(stateDim),
        z(measureDim),
        Q(_Q),
        R(_R),
        P(_P)
    {
        ASSERT_TRUE_P(f->inputs == stateDim,
                ("F should map from the state size %d != %d", f->inputs, stateDim));
        ASSERT_TRUE_P(f->outputs == stateDim,
                ("F should map to the state size %d != %d", f->outputs, stateDim));
        ASSERT_TRUE_P(P.h == stateDim && P.w == stateDim,
                ("P should be square and equal to state size [%d x %d], %d ", P.h, P.w, stateDim));
        ASSERT_TRUE_P(Q.h == stateDim && Q.w == stateDim,
                ("Q should be square and equal to state size [%d x %d], %d", Q.h, Q.w, stateDim));

    }

    virtual ~ClassicKalman();

    int stateDim;
    int measureDim;

    FunctionArgs *f;
    FunctionArgs *h;
    Vector x;
    Vector xPredicted;

    Vector z;

    Matrix Q;
    Matrix R;
    Matrix P;


    void predict( void );
    void update( void );

};


} //namespace corecvs
#endif /* CLASSICKALMAN_H_ */

