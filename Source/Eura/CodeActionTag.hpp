// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_code_action_tag
#define lyrix_header_guard_eura_code_action_tag
#include <cstdint>

namespace Eura
{
    enum class [[nodiscard]] CodeActionTag : std::uint8_t
    {
        LLMGenerated = 1u
    };
}

#endif
#endif