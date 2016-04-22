#ifndef EDTOOLS_FERMION_HASH_HPP
#define EDTOOLS_FERMION_HASH_HPP

namespace edtools {
  template <typename BITSET, typename CODE>
  class FermionConfigs {
  public:
    typedef BITSET bitset_type;
    typedef CODE code_type;
    typedef unsigned size_type;

    typedef ConfigGenIterator<bitset_type> const_iterator;

  public:
    FermionConfigs(size_type n, size_type np)
      : m_n(n), m_np(np) {
      if (n > bitset_type::max_size)
	throw std::out_of_range("FermionConfigs bitset_type not long enough");
      if (np == 0 || np >= n)
	throw std::out_of_range("Wrong parameter: requires 0 < np < n");

      for (size_type i=0; i < n+1; ++i) {
	binomial_map(i, 0) = 1;
	binomial_map(i, i) = 1;
	for (size_type j=1; j < i; ++j)
	  binomial_map(i, j) = binomial_map(i-1, j-1)
	    + binomial_map(i-1, j);
	for (size_type j=i+1; j < n+1; ++j)
	  binomial_map(i, j) = 0;
      }
    }

    code_type find_code(bitset_type conf) {
      assert(m_n == conf.size());
      size_type count = 1;
      code_type code = 0;
      for (size_type i=0; i < m_n; ++i) {
	if (conf[i]) {
	  code += binominal_map(i, count);
	  ++count;
	}
      }

      return code;
    }

    const_iterator begin() const {
    }

  private:
    size_type m_n;
    size_type m_np;
    MatrixType m_binomial_map;
  };
}

#endif
