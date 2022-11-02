
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef BOOST_TT_IS_COMPOUND_HPP_INCLUDED
#define BOOST_TT_IS_COMPOUND_HPP_INCLUDED

#include <dgboost/type_traits/is_fundamental.hpp>

namespace dgboost {} namespace boost = dgboost; namespace dgboost {

#if defined( BOOST_CODEGEARC )
   template <class T> struct is_compound : public integral_constant<bool, __is_compound(T)> {};
#else
   template <class T> struct is_compound : public integral_constant<bool, ! ::dgboost::is_fundamental<T>::value> {};
#endif

} // namespace dgboost

#endif // BOOST_TT_IS_COMPOUND_HPP_INCLUDED
