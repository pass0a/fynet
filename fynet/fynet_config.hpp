#include <stdint.h>
#ifdef USE_FLOAT32
typedef float_t data_type;
#elif USE_FLOAT64
typedef double data_type;
#elif USE_INT8
typedef int data_type;
#endif
