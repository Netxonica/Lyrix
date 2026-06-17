// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_diagnostic_tag
#define lyrix_header_guard_eura_diagnostic_tag
#include "Eura/Uinteger.hpp"

namespace Eura
{
    using DiagnosticTag = Json::Uinteger;
    
    inline const constexpr DiagnosticTag Unnecessary = 1u, Deprecated = 2u;
}

#endif
#endif