#ifndef EDTOOLS_DYNAMIC_BITSET_HPP
#define EDTOOLS_DYNAMIC_BITSET_HPP

#include "count_bits.hpp"

namespace edtools {
  template <typename BASETYPE>
  class dyn_bitset {
  public:
    typedef BASETYPE base_type;
    typedef unsigned size_type;
    typedef dyn_bitset<BaseType> self_type;
    static const size_type max_size = sizeof(BaseType)*8;

  public:
    dyn_bitset(size_type n, base_type data = 0)
      : m_data(data) {
      assert(n < max_size);
      assert(ffs() <= n);
#ifndef NDEBUG
      m_size = n;
#endif
    }

    dyn_bitset(const self_type&) = default;

  public:
    bool operator[] (size_type pos) const {
      assert(pos < m_size);
      return (m_data & (base_type(1u) << pos) ) != 0;
    }

    self_type& set(size_type pos) {
      assert(pos < m_size);
      m_data |= base_type(1u) << pos; return *this;
    }

    self_type& unset(size_type pos) {
      assert(pos < m_size);
      m_data &= ~(base_type(1u) << pos); return *this;
    }

    void swap_bits(size_type pos1, size_type pos2) {
      assert(pos1 < m_size && pos2 < m_size);
      BaseType x = ((m_data>>pos1) ^ (m_data>>pos2)) & BaseType{1u};
      m_data ^= ((x<<pos1) | (x<<pos2));
    }

    size_type count() const {
      return dyn_bitset_impl::CountBits<base_type>::op(m_data);
    }

    size_type ffs() const {
      return dyn_bitset_impl::FFS<base_type>::op(m_data);
    }

  private:
    base_type m_data;
#ifndef NDEBUG
    size_type m_size;
#endif
  };
}

#endif
