// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_diagnostic_severity
#define lyrix_header_guard_eura_diagnostic_severity
#include <cstdint>

namespace Eura
{
    enum class [[nodiscard]] DiagnosticSeverity : std::uint8_t
    {
        Error = 1u,
        Warning = 2u,
        Information = 3u,
        Hint = 4u
    };
}

#endif
#endif