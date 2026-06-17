// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_type
#define lyrix_header_guard_eura_type
#include <cstdint>

namespace Eura::Json
{
    enum class [[nodiscard]] Type : std::uint8_t
    {
        // Literals
        Natural = 0u,
        Integer = 1u,
        Real = 2u,
        String = 3u,
        MutatedString = 4u, // mutated strings stored in the Eura::Strings database

        // Keywords
        Null = 5u, // null
        True = 6u, // true
        False = 7u, // false

        // Punctuators
        StartArray = 8u, // [
        EndArray = 9u, // ]
        StartObject = 10u, // {
        EndObject = 11u, // }
        Colon = 12u, // :
        Comma = 13u // ,
    };
}

#endif
#endif