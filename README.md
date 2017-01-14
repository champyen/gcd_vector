# gcd_vector
clang extended vector + libdispatch optimization example

Raspberry Pi 3: 114X
- test 18700284 us
- test_tile 2160980 us
- test_vec 358326 us
- test_gcd 6778646 us
- test_gcd_tile 1085776 us
- test_gcd_vec 164121 us

A8-5545m: 15X 
- test 446682 us
- test_tile 2613739 us
- test_vec 48856 us
- test_gcd 239297 us
- test_gcd_tile 2638397 us
- test_gcd_vec 29957 us

i7-3612QM: 23.4X
- test 275879 us
- test_tile 224157 us
- test_vec 31457 us
- test_gcd 112845 us
- test_gcd_tile 92521 us
- test_gcd_vec 11808 us
