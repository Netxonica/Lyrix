// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_watch_kind
#define lyrix_header_guard_eura_watch_kind
#include <cstdint>

namespace Eura
{
    enum class [[nodiscard]] WatchKind : std::uint32_t
    {
        Create = 1u,
        Change = 2u,
        Delete = 4u
    };
}

#endif
#endif