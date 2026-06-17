// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_regular_expression_engine_kind
#define lyrix_header_guard_eura_regular_expression_engine_kind
#include "Eura/String.hpp"

namespace Eura
{
    using RegularExpressionEngineKind = Json::String;

    inline const constexpr RegularExpressionEngineKind ES2020 = "ES2020";
}

#endif
#endif