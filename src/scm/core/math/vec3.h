
#ifndef MATH_VEC3_H_INCLUDED
#define MATH_VEC3_H_INCLUDED

#include "vec.h"

namespace scm {
namespace math {

template<typename scal_type>
class vec<scal_type, 3>
{
public:
    typedef scal_type   value_type;

public:
    // ctors
    vec();
    vec(const vec<scal_type, 3>& v);
    //vec(const scal_type a[3]);

    vec(const vec<scal_type, 2>& v,
        const scal_type          z = scal_type(0));
    vec(const vec<scal_type, 4>& v);

    explicit vec(const scal_type s);
    explicit vec(const scal_type s,
                 const scal_type t,
                 const scal_type u);

    template<typename rhs_scal_t> explicit vec(const vec<rhs_scal_t, 3>& v);

    // dtor
    //~vec();

    // swap
    void swap(vec<scal_type, 3>& rhs);

    // assign
    vec<scal_type, 3>&              operator=(const vec<scal_type, 3>& rhs);
    template<typename rhs_scal_t>
    vec<scal_type, 3>&              operator=(const vec<rhs_scal_t, 3>& rhs);

    // data access
    //inline scal_type*const          operator&()          { return (data_array); }
    //inline const scal_type*const    operator&() const    { return (data_array); }

    // index
    inline scal_type&               operator[](const int i)         { return data_array[i]; };
    inline scal_type                operator[](const int i) const   { return data_array[i]; };

    // unary operators
    vec<scal_type, 3>&              operator+=(const scal_type          s);
    vec<scal_type, 3>&              operator+=(const vec<scal_type, 3>& v);
    vec<scal_type, 3>&              operator-=(const scal_type          s);
    vec<scal_type, 3>&              operator-=(const vec<scal_type, 3>& v);
    vec<scal_type, 3>&              operator*=(const scal_type          s);
    vec<scal_type, 3>&              operator*=(const vec<scal_type, 3>& v);
    vec<scal_type, 3>&              operator/=(const scal_type          s);
    vec<scal_type, 3>&              operator/=(const vec<scal_type, 3>& v);

    // data definition
    union {
        struct {scal_type x, y, z;};
        struct {scal_type r, g, b;};
        struct {scal_type s, t, p;};
        scal_type data_array[3];
    };

}; // class vec<scal_type, 3>

} // namespace math
} // namespace scm

#include "vec3.inl"

#endif // MATH_VEC3_H_INCLUDED
