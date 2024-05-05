#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(n, b) (n = n | (1 << b))

#define CLR_BIT(n, b) (n = n & ~(1 << b))

#define TOG_BIT(n, b) (n = n ^ (1 << b))

//#define GET_BIT(n, b) ((n >> b) & 1)

#define GET_BIT(n, b) (((n) >> (b)) & 1)

#endif
