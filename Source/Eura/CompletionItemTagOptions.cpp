// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CompletionItemTagOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CompletionItemTagOptions&
    completion_item_tag_options) noexcept -> void
    {
        const nlohmann::json& valueSet = object.at("valueSet");
        for(const nlohmann::json& value : valueSet)
            completion_item_tag_options.valueSet.emplace_back(static_cast<CompletionItemTag>(value.
            get<std::uint8_t>()));
    }

    auto to_json(nlohmann::json& object, const CompletionItemTagOptions&
    completion_item_tag_options) noexcept -> void
    {
        nlohmann::json valueSet = nlohmann::json::array();
        for(const CompletionItemTag value : completion_item_tag_options.valueSet)
            valueSet.emplace_back(static_cast<std::uint8_t>(value));
        object["valueSet"] = valueSet;
    }
}

#endif