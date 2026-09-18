// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_notebook_cell_kind
#define lyrix_header_guard_eura_notebook_cell_kind
#include <cstdint>

namespace Eura
{
    enum class [[nodiscard]] NotebookCellKind : std::uint8_t
    {
        Markup = 1u,
        Code = 2u
    };
}

#endif
#endif