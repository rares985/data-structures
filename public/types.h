#ifndef TYPES_H_
#define TYPES_H_

typedef enum {
    ERR_STRUCTURE_FULL = -4,
    ERR_NO_MEMORY = -3,
    ERR_INVALID_PARAMS = -2,
    ERR_GENERIC = -1,
    ERR_OK = 0
} error_t;

#endif /* TYPES_H_ */