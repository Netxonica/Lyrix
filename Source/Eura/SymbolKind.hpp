// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_symbol_kind
#define lyrix_header_guard_eura_symbol_kind
#include <cstdint>

namespace Eura
{
    enum class [[nodiscard]] SymbolKind : std::uint8_t
    {
        File = 1u,
        Module = 2u,
        Namespace = 3u,
        Package = 4u,
        Class = 5u,
        Method = 6u,
        Property = 7u,
        Field = 8u,
        Constructor = 9u,
        Enum = 10u,
        Interface = 11u,
        Function = 12u,
        Variable = 13u,
        Constant = 14u,
        String = 15u,
        Number = 16u,
        Boolean = 17u,
        Array = 18u,
        Object = 19u,
        Key = 20u,
        Null = 21u,
        EnumMember = 22u,
        Struct = 23u,
        Event = 24u,
        Operator = 25u,
        TypeParameter = 26u
    };
}

#endif
#endif