// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_completion_trigger_kind
#define lyrix_header_guard_eura_completion_trigger_kind
#include <cstdint>

namespace Eura
{
    enum class [[nodiscard]] CompletionTriggerKind : std::uint8_t
    {
        Invoked = 1u,
        TriggerCharacter = 2u,
        TriggerForIncompleteCompletions = 3u
    };
}

#endif
#endif