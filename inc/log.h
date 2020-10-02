#ifndef LOG_H_
#define LOG_H_

#include "stdio.h"
#include "stdlib.h"

#define LOG_ERR(format, ...)  fprintf(stderr, format"\n", ##__VA_ARGS__)
#define LOG_INF(format, ...)  fprintf(stdout, format"\n", ##__VA_ARGS__)
#define LOG_INF_NOENDL(format, ...)  fprintf(stdout, format, ##__VA_ARGS__)

#endif /* LOG_H_ */
