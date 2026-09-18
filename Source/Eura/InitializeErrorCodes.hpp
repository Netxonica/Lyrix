// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_initialize_error_codes
#define lyrix_header_guard_eura_initialize_error_codes
#include <cstdint>

namespace Eura
{
    enum class [[nodiscard]] InitializeErrorCodes : std::uint8_t
    {
        unknownProtocolVersion = 1u
    };
}

#endif
#endif