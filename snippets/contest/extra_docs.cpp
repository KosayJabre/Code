// 128-bit integer
__int128 a;
unsigned __int128 b;

// 128-bit float
// minor improvements over long double
__float128 c;

// log2 floor
__lg(n);

// number of 1 bits
// can add ll like popcountll for long longs
__builtin_popcount(n);

// number of trailing zeroes
__builtin_ctz(n);

// number of leading zeroes
__builtin_clz(n);

// 1-indexed least significant 1 bit
__builtin_ffs(n);

// parity of number
__builtin_parity(n);
