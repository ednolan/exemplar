// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef BEMAN_EXEMPLAR_IDENTITY_HPP
#define BEMAN_EXEMPLAR_IDENTITY_HPP

// C++ Standard Library: std::identity equivalent.
// See https://eel.is/c++draft/func.identity:
//
// 22.10.12 Class identity  [func.identity]
//
// struct identity {
//   template<class T>
//     constexpr T&& operator()(T&& t) const noexcept;
//
//   using is_transparent = unspecified;
// };
//
// template<class T>
//   constexpr T&& operator()(T&& t) const noexcept;
//
// Effects: Equivalent to: return std::forward<T>(t);

#include <utility> // std::forward

namespace beman::exemplar {

struct __is_transparent; // not defined

// A function object that returns its argument unchanged.
struct identity {
    // Returns `t`.
    template <class T>
    constexpr T&& operator()(T&& t) const noexcept {
        return std::forward<T>(t);
    }

    using is_transparent = __is_transparent;
};

} // namespace beman::exemplar

#if __has_include("experimental/meta")

#include <experimental/meta>
#include <iostream>
#include <cassert>
#include <utility>

struct S { unsigned i:2, j:6; };

consteval auto member_number(int n) {
  if (n == 0) return ^^S::i;
  else if (n == 1) return ^^S::j;

  std::unreachable();
}

int foo() {
  S s{0, 0};
  s.[:member_number(1):] = 42;  // Same as: s.j = 42;
  std::cout << "s.i=" << s.i << ", s.j=" << s.j << '\n';
}

#endif

#endif // BEMAN_EXEMPLAR_IDENTITY_HPP
