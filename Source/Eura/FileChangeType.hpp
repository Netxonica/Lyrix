// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_file_change_type
#define lyrix_header_guard_eura_file_change_type
#include <cstdint>

namespace Eura
{
    enum class [[nodiscard]] FileChangeType : std::uint8_t
    {
        Created = 1u,
        Changed = 2u,
        Deleted = 3u
    };
}

#endif
#endif