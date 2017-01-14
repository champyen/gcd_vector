# gcd_vector
clang extended vector + libdispatch optimization example

Raspberry Pi 3:
- test 18700284 us
- test_tile 2160980 us
- test_vec 358326 us
- test_gcd 6778646 us
- test_gcd_tile 1085776 us
- test_gcd_vec 164121 us

A8-5545m
- test 446682 us
- test_tile 2613739 us
- test_vec 48856 us
- test_gcd 239297 us
- test_gcd_tile 2638397 us
- test_gcd_tile 29957 us
