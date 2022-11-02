/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef BOOST_PREDEF_COMPILER_KAI_H
#define BOOST_PREDEF_COMPILER_KAI_H

#include <dgboost/predef/version_number.h>
#include <dgboost/predef/make.h>

/* tag::reference[]
= `BOOST_COMP_KCC`

Kai {CPP} compiler.
Version number available as major, minor, and patch.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__KCC+` | {predef_detection}

| `+__KCC_VERSION+` | V.R.P
|===
*/ // end::reference[]

#define BOOST_COMP_KCC BOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__KCC)
#   define BOOST_COMP_KCC_DETECTION BOOST_PREDEF_MAKE_0X_VRPP(__KCC_VERSION)
#endif

#ifdef BOOST_COMP_KCC_DETECTION
#   if defined(BOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define BOOST_COMP_KCC_EMULATED BOOST_COMP_KCC_DETECTION
#   else
#       undef BOOST_COMP_KCC
#       define BOOST_COMP_KCC BOOST_COMP_KCC_DETECTION
#   endif
#   define BOOST_COMP_KCC_AVAILABLE
#   include <dgboost/predef/detail/comp_detected.h>
#endif

#define BOOST_COMP_KCC_NAME "Kai C++"

#endif

#include <dgboost/predef/detail/test.h>
BOOST_PREDEF_DECLARE_TEST(BOOST_COMP_KCC,BOOST_COMP_KCC_NAME)

#ifdef BOOST_COMP_KCC_EMULATED
#include <dgboost/predef/detail/test.h>
BOOST_PREDEF_DECLARE_TEST(BOOST_COMP_KCC_EMULATED,BOOST_COMP_KCC_NAME)
#endif
