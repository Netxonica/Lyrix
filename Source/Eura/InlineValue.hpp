// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_inline_value
#define lyrix_header_guard_eura_inline_value
#include "Eura/InlineValueText.hpp"
#include "Eura/InlineValueVariableLookup.hpp"
#include "Eura/InlineValueEvaluatableExpression.hpp"

namespace Eura
{
    using InlineValue = std::variant<InlineValueText, InlineValueVariableLookup,
    InlineValueEvaluatableExpression>;
}

#endif
#endif