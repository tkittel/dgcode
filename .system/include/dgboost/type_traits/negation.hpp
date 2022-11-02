/*
Copyright 2020 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License,
Version 1.0. (See accompanying file LICENSE_1_0.txt
or copy at http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef BOOST_TT_NEGATION_HPP_INCLUDED
#define BOOST_TT_NEGATION_HPP_INCLUDED

#include <dgboost/type_traits/integral_constant.hpp>

namespace dgboost {} namespace boost = dgboost; namespace dgboost {

template<class T>
struct negation
    : integral_constant<bool, !bool(T::value)> { };

} /* boost */

#endif
