/**
 * \file correspondanceList.h
 * \brief Add Comment Here
 *
 * \ingroup cppcorefiles
 * \date Mar 24, 2010
 * \author alexander
 */

#ifndef CCORRESPONDANCELIST_H_
#define CCORRESPONDANCELIST_H_

#include <vector>
#include "vector2d.h"
#include "flowBuffer.h"
#include "floatFlowBuffer.h"
#include "projectiveTransform.h"

namespace corecvs {

using std::vector;

template<class FirstType, class SecondType>
class PrimitiveCorrespondance
{
public:
    enum CorrespondanceFlags{
          FLAG_NONE           = 0x00,
          FLAG_FILTERED_KLT   = 0x01,
          FLAG_FILTERED_SHORT = 0x02,
          FLAG_FAILER         = 0x04,
          FLAG_PASSER         = 0x08,
          FLAG_IS_BASED_ON    = 0x10,
          FLAG_FILTER_MASK    = FLAG_FILTERED_KLT | FLAG_FILTERED_SHORT
      };


    FirstType  start; /**< \brief The point in the "left" image */
    SecondType end;   /**< \brief The point in the "right" image */
    uint16_t value;   /**< \brief The weight of the correspondence */
    uint16_t flags;   /**< \brief Some flags */

    PrimitiveCorrespondance() {};
    PrimitiveCorrespondance(FirstType _start, SecondType _end) :
        start(_start),
        end(_end),
        value(0),
        flags(FLAG_NONE)
    {};

    void clearFlags( void )
    {
        flags = FLAG_NONE;
    }

    double correspondanceLength( void ) const
    {
        return (start - end).l2Metric();
    }

    bool isFiltered( void ) const
    {
        return (flags & FLAG_FILTER_MASK) != 0;
    }
};

typedef PrimitiveCorrespondance<Vector2dd, Vector2dd> Correspondance;

class CorrespondanceList : public vector<Correspondance>
{
public:
    int h;
    int w;

    CorrespondanceList();
    CorrespondanceList(const CorrespondanceList &list);
    CorrespondanceList(FlowBuffer *input, bool swap = false);
    CorrespondanceList(FloatFlowBuffer *input);


    virtual ~CorrespondanceList();

    void getNormalizingTransform(Matrix33 &transformRight, Matrix33 &transformLeft, double *scale);

    void transform(const ProjectiveTransform &transformRight, const ProjectiveTransform &transformLeft);

    CorrespondanceList *makePreciseCopy(G12Buffer *first, G12Buffer *second);
    void                makePrecise(G12Buffer *first, G12Buffer *second);

    void resetFlags( void )
    {
        iterator it;
        for (it = begin(); it != end(); ++it)
        {
            (*it).clearFlags();
        }
    }

    Vector2dd getSize() const
    {
        return Vector2dd(w, h);
    }

    Vector2dd getMeanDifference()
    {
      Vector2dd mean (0.0);
      for (unsigned i = 0; i < size(); i++)
      {
      	Correspondance *corr = &(at(i));
      	mean += (corr->end - corr->start);

      }
      return (size() != 0) ? mean / size() : Vector2dd(0.0);
    }
};


/**
 *   DerivedCorrespondanceList is a wrapper around CorrespondanceList
 * that allows to modify the contense, yet remembering the pointer to the
 * origin
 **/
class DerivedCorrespondanceList : public CorrespondanceList
{
public:
    CorrespondanceList* parent;
    vector<int> map;

    DerivedCorrespondanceList(CorrespondanceList *list) :
        CorrespondanceList(*list),
        parent(list)
    {
        map.reserve(parent->size());
        for (unsigned i = 0; i < parent->size(); i++)
            map.push_back(i);
    }

    template<class Predicate>
    DerivedCorrespondanceList(CorrespondanceList *list, Predicate &predicate, int flag) :
        parent(list)
    {
        /* Some extra memory used */
        unsigned parentSize = (unsigned)parent->size();
        reserve(parentSize);
        map.reserve(parentSize);

        for (unsigned i = 0; i < parentSize; i++)
        {
            if (!predicate(parent->at(i)))
            {
                parent->at(i).flags |= flag;
                continue;
            }
            map.push_back(i);
            push_back(parent->at(i));
        }
    }

    void propagateData( void )
    {
        for (unsigned i = 0; i < size(); i++)
        {
            parent->at(map[i]).value = operator [](i).value;
            parent->at(map[i]).flags = operator [](i).flags;
        }
    }

    vector<Correspondance *> *toArrayOfPointers()
    {
        vector<Correspondance *> *result = new vector<Correspondance *>();
        result->reserve(this->size());
        for(unsigned i = 0; i < this->size(); i++)
        {
            result->push_back(&(at(i)));
        }
        return result;
    }
};


} //namespace corecvs
#endif /* CCORRESPONDANCELIST_H_ */

