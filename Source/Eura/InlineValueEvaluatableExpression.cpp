// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlineValueEvaluatableExpression.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InlineValueEvaluatableExpression&
    inline_value_evaluatable_expression) noexcept -> void
    {
        inline_value_evaluatable_expression.range = object.at("range").get<Range>();
        if(object.contains("expression"))
            inline_value_evaluatable_expression.expression = object.at("expression").get<std::
            string>();
    }

    auto to_json(nlohmann::json& object, const InlineValueEvaluatableExpression&
    inline_value_evaluatable_expression) noexcept -> void
    {
        object["range"] = inline_value_evaluatable_expression.range;
        if(inline_value_evaluatable_expression.expression.has_value())
            object["expression"] = *inline_value_evaluatable_expression.expression;
    }
}

#endif