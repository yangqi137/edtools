#ifndef YANGQI_EDTOOLS_DYN_BITSET_COUNT_BITS_HPP
#define YANGQI_EDTOOLS_DYN_BITSET_COUNT_BITS_HPP

#ifdef __SSE4__
#include <cstdint>
#include <nmmintrin.h>
#endif

namespace edtools {
  namespace dyn_bitset_impl {
    template <typename T>
    struct CountBits {
      static unsigned op(BitsetType n) {
	unsigned count=0;
	while (n) {
	  count++;
	  n &= n-1;
	}
	return count;
      }
    };
    
#ifdef __SSE4__
    template<>
    struct CountBits<uint32_t> {
      static unsigned op(uint32_t n) {
	return _mm_popcnt_u32(n);
      }
    };

    template<>
    struct CountBits<uint64_t> {
      inline unsigned op(uint64_t n) {
	return _mm_popcnt_u64(n);
      }
    };
#endif
    
  }
}

#endif
