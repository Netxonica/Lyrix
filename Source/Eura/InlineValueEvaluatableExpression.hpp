// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_inline_value_evaluatable_expression
#define lyrix_header_guard_eura_inline_value_evaluatable_expression
#include "Eura/Range.hpp"

namespace Eura
{
    struct [[nodiscard]] InlineValueEvaluatableExpression final
    {
        Range range;

        std::optional<std::string> expression;
    };

    auto from_json(const nlohmann::json& object, InlineValueEvaluatableExpression&
    inline_value_evaluatable_expression) noexcept -> void;

    auto to_json(nlohmann::json& object, const InlineValueEvaluatableExpression&
    inline_value_evaluatable_expression) noexcept -> void;
}

#endif
#endif