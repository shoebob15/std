#include "util.h"

char* _log_level_to_string(LogLevel level) {
    switch (level) {
        case LOG_INFO: return "INF";
        case LOG_WARN: return "WRN";
        case LOG_ERROR: return "ERR";
        default: return "OTHR";
    }
}
