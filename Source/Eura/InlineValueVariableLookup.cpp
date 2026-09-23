// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlineValueVariableLookup.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InlineValueVariableLookup&
    inline_value_variable_lookup) noexcept -> void
    {
        inline_value_variable_lookup.range = object.at("range").get<Range>();
        if(object.contains("variableName"))
            inline_value_variable_lookup.variableName = object.at("variableName").get<std::string>(
            );
        inline_value_variable_lookup.caseSensitiveLookup = object.at("caseSensitiveLookup").get<
        bool>();
    }

    auto to_json(nlohmann::json& object, const InlineValueVariableLookup&
    inline_value_variable_lookup) noexcept -> void
    {
        object["range"] = inline_value_variable_lookup.range;
        if(inline_value_variable_lookup.variableName.has_value())
            object["variableName"] = *inline_value_variable_lookup.variableName;
        object["caseSensitiveLookup"] = inline_value_variable_lookup.caseSensitiveLookup;
    }
}

#endif