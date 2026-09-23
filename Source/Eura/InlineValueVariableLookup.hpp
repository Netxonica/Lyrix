// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_inline_value_variable_lookup
#define lyrix_header_guard_eura_inline_value_variable_lookup
#include "Eura/Range.hpp"

namespace Eura
{
    struct [[nodiscard]] InlineValueVariableLookup final
    {
        Range range;

        std::optional<std::string> variableName;

        bool caseSensitiveLookup;
    };

    auto from_json(const nlohmann::json& object, InlineValueVariableLookup&
    inline_value_variable_lookup) noexcept -> void;

    auto to_json(nlohmann::json& object, const InlineValueVariableLookup&
    inline_value_variable_lookup) noexcept -> void;
}

#endif
#endif