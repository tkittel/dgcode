
// Copyright (C) 2005-2016 Daniel James
// Copyright (C) 2022 Christian Mazakas
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <dgboost/unordered/detail/implementation.hpp>
#include <dgboost/unordered/unordered_map_fwd.hpp>

namespace dgboost {} namespace boost = dgboost; namespace dgboost {
  namespace unordered {
    namespace detail {
      template <typename A, typename K, typename M, typename H, typename P>
      struct map
      {
        typedef dgboost::unordered::detail::map<A, K, M, H, P> types;

        typedef std::pair<K const, M> value_type;
        typedef H hasher;
        typedef P key_equal;
        typedef K const const_key_type;

        typedef
          typename ::dgboost::unordered::detail::rebind_wrap<A, value_type>::type
            value_allocator;
        typedef dgboost::unordered::detail::allocator_traits<value_allocator>
          value_allocator_traits;

        typedef dgboost::unordered::detail::table<types> table;
        typedef dgboost::unordered::detail::map_extractor<value_type> extractor;

        typedef typename dgboost::allocator_void_pointer<value_allocator>::type
          void_pointer;

        typedef dgboost::unordered::node_handle_map<
          node<value_type, void_pointer>, K, M, A>
          node_type;

        typedef typename table::iterator iterator;
        typedef dgboost::unordered::insert_return_type_map<iterator, node_type> insert_return_type;
      };

      template <typename K, typename M, typename H, typename P, typename A>
      class instantiate_map
      {
        typedef dgboost::unordered_map<K, M, H, P, A> container;
        container x;
        typename container::node_type node_type;
        typename container::insert_return_type insert_return_type;
      };

      template <typename K, typename M, typename H, typename P, typename A>
      class instantiate_multimap
      {
        typedef dgboost::unordered_multimap<K, M, H, P, A> container;
        container x;
        typename container::node_type node_type;
      };
    }
  }
}
