// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_message_type
#define lyrix_header_guard_eura_message_type
#include <cstdint>

namespace Eura
{
    enum class [[nodiscard]] MessageType : std::uint8_t
    {
        Error = 1u,
        Warning = 2u,
        Info = 3u,
        Log = 4u,
        Debug = 5u
    };
}

#endif
#endif