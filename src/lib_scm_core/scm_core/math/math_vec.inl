
#ifndef SCM_MATH_VEC_INL_INCLUDED
#define SCM_MATH_VEC_INL_INCLUDED

#include <cassert>
#include <cmath>

namespace math
{
    template<typename scm_scalar, unsigned dim>
    inline bool operator==(const vec<scm_scalar, dim>& lhs, const vec<scm_scalar, dim>& rhs)
    {
        bool tmp_ret = true;

        for (unsigned i = 0; i < dim && tmp_ret; i++) {
            tmp_ret = (lhs.vec_array[i] == rhs.vec_array[i]); // TODO something like epsilon compare
        }

        return (tmp_ret);
    }

    template<typename scm_scalar, unsigned dim>
    inline bool operator!=(const vec<scm_scalar, dim>& lhs, const vec<scm_scalar, dim>& rhs)
    {
        bool tmp_ret = false;

        for (unsigned i = 0; i < dim && !tmp_ret; i++) {
            tmp_ret = (lhs.vec_array[i] != rhs.vec_array[i]); // TODO something like epsilon compare
        }

        return (tmp_ret);
    }

    template<typename scm_scalar, unsigned dim>
    inline const scm_scalar*const operator&(const vec<scm_scalar, dim>& v)
    {
        return (v.vec_array);
    }

    template<typename scm_scalar, unsigned dim>
    inline vec<scm_scalar, dim>& operator+=(vec<scm_scalar, dim>& lhs, const vec<scm_scalar, dim>& rhs)
    {
        for (unsigned i = 0; i < dim; i++) {
            lhs.vec_array[i] += rhs.vec_array[i];
        }
        return (lhs);
    }

    template<typename scm_scalar, unsigned dim>
    inline vec<scm_scalar, dim>& operator-=(vec<scm_scalar, dim>& lhs, const vec<scm_scalar, dim>& rhs)
    {
        for (unsigned i = 0; i < dim; i++) {
            lhs.vec_array[i] -= rhs.vec_array[i];
        }
        return (lhs);
    }

    template<typename scm_scalar, unsigned dim>
    inline vec<scm_scalar, dim>& operator*=(vec<scm_scalar, dim>& lhs, const vec<scm_scalar, dim>& rhs)
    {
        for (unsigned i = 0; i < dim; i++) {
            lhs.vec_array[i] *= rhs.vec_array[i];
        }
        return (lhs);
    }

    template<typename scm_scalar, unsigned dim>
    inline vec<scm_scalar, dim>& operator/=(vec<scm_scalar, dim>& lhs, const vec<scm_scalar, dim>& rhs)
    {
        for (unsigned i = 0; i < dim; i++) {
            lhs.vec_array[i] /= rhs.vec_array[i];
        }
        return (lhs);
    }

    template<typename scm_scalar, unsigned dim>
    inline vec<scm_scalar, dim>& operator*=(vec<scm_scalar, dim>& lhs, const scm_scalar rhs)
    {
        for (unsigned i = 0; i < dim; i++) {
            lhs.vec_array[i] *= rhs;
        }
        return (lhs);
    }

    template<typename scm_scalar, unsigned dim>
    inline vec<scm_scalar, dim>& operator/=(vec<scm_scalar, dim>& lhs, const scm_scalar rhs)
    {
        for (unsigned i = 0; i < dim; i++) {
            lhs.vec_array[i] /= rhs;
        }
        return (lhs);
    }

    template<typename scm_scalar, unsigned dim>
    inline const vec<scm_scalar, dim> operator-(const vec<scm_scalar, dim>& lhs)
    {
        vec<scm_scalar, dim> tmp_ret;

        for (unsigned i = 0; i < dim; i++) {
            tmp_ret.vec_array[i] = -lhs.vec_array[i];
        }

        return (tmp_ret);
    }

    template<typename scm_scalar, unsigned dim>
    inline const vec<scm_scalar, dim> operator+(const vec<scm_scalar, dim>& lhs, const vec<scm_scalar, dim>& rhs)
    {
        vec<scm_scalar, dim> tmp_ret;

        for (unsigned i = 0; i < dim; i++) {
            tmp_ret.vec_array[i] = lhs.vec_array[i] + rhs.vec_array[i];
        }

        return (tmp_ret);
    }

    template<typename scm_scalar, unsigned dim>
    inline const vec<scm_scalar, dim> operator-(const vec<scm_scalar, dim>& lhs, const vec<scm_scalar, dim>& rhs)
    {
        vec<scm_scalar, dim> tmp_ret;

        for (unsigned i = 0; i < dim; i++) {
            tmp_ret.vec_array[i] = lhs.vec_array[i] - rhs.vec_array[i];
        }

        return (tmp_ret);
    }

    template<typename scm_scalar, unsigned dim>
    inline const vec<scm_scalar, dim> operator*(const vec<scm_scalar, dim>& lhs, const vec<scm_scalar, dim>& rhs)
    {
        vec<scm_scalar, dim> tmp_ret;

        for (unsigned i = 0; i < dim; i++) {
            tmp_ret.vec_array[i] = lhs.vec_array[i] * rhs.vec_array[i];
        }

        return (tmp_ret);
    }

    template<typename scm_scalar, unsigned dim>
    inline const vec<scm_scalar, dim> operator/(const vec<scm_scalar, dim>& lhs, const vec<scm_scalar, dim>& rhs)
    {
        vec<scm_scalar, dim> tmp_ret;

        for (unsigned i = 0; i < dim; i++) {
            tmp_ret.vec_array[i] = lhs.vec_array[i] / rhs.vec_array[i];
        }

        return (tmp_ret);
    }

    template<typename scm_scalar, unsigned dim>
    inline const vec<scm_scalar, dim> operator*(const vec<scm_scalar, dim>& lhs, const scm_scalar rhs)
    {
        vec<scm_scalar, dim> tmp_ret;

        for (unsigned i = 0; i < dim; i++) {
            tmp_ret.vec_array[i] = lhs.vec_array[i] * rhs;
        }

        return (tmp_ret);
    }

    template<typename scm_scalar, unsigned dim>
    inline const vec<scm_scalar, dim> operator*(const scm_scalar lhs, const vec<scm_scalar, dim>& rhs)
    {
        vec<scm_scalar, dim> tmp_ret;

        for (unsigned i = 0; i < dim; i++) {
            tmp_ret.vec_array[i] = lhs * rhs.vec_array[i];
        }

        return (tmp_ret);
    }

    template<typename scm_scalar, unsigned dim>
    inline const vec<scm_scalar, dim> operator/(const vec<scm_scalar, dim>& lhs, const scm_scalar rhs)
    {
        vec<scm_scalar, dim> tmp_ret;

        for (unsigned i = 0; i < dim; i++) {
            tmp_ret.vec_array[i] = lhs.vec_array[i] / rhs;
        }

        return (tmp_ret);
    }

} // math

#endif // SCM_MATH_VEC_INL_INCLUDED

