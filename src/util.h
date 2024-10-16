#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "array.h" // for files including util

typedef enum {
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
} LogLevel;

char* _log_level_to_string(LogLevel level);

// TODO: line and file for log
#define LOG(level, format, ...) \
    do { \
        fprintf(stderr, "[%s] ", _log_level_to_string(level)); \
        fprintf(stderr, format, ##__VA_ARGS__); \
        fprintf(stderr, "\n"); \
    } while (0)


#define ASSERT(e) \
    do { \
        if (!(e)) { \
            LOG(LOG_ERROR, "Assertion failed: %s", #e); \
            exit(1); \
        } \
    } while (0)


// typedefs
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
