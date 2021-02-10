#ifndef _COMMON_TYPES_HEADER
#define _COMMON_TYPES_HEADER

#include <string>
#include <vector>
#include <unordered_map>
#include <cassert>

template <typename T>
using TFVector = std::vector<T>;

using TFString = std::string;

template <typename Key, typename Value>
using TFUnorderedMap = std::unordered_map<Key, Value>;

struct TFError 
{
    unsigned row;
    unsigned column;
    TFString what;
};

#define NOT_IMPLEMENTED assert(0 && "not-implemented")

#endif