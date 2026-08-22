// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_completion_item_kind
#define lyrix_header_guard_eura_completion_item_kind
#include <cstdint>

namespace Eura
{
    enum class [[nodiscard]] CompletionItemKind : std::uint8_t
    {
        Text = 1u,
        Method = 2u,
        Function = 3u,
        Constructor = 4u,
        Field = 5u,
        Variable = 6u,
        Class = 7u,
        Interface = 8u,
        Module = 9u,
        Property = 10u,
        Unit = 11u,
        Value = 12u,
        Enum = 13u,
        Keyword = 14u,
        Snippet = 15u,
        Color = 16u,
        File = 17u,
        Reference = 18u,
        Folder = 19u,
        EnumMember = 20u,
        Constant = 21u,
        Struct = 22u,
        Event = 23u,
        Operator = 24u,
        TypeParameter = 25u
    };
}

#endif
#endif