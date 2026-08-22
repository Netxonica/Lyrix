// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientCompletionItemOptionsKind.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ClientCompletionItemOptionsKind&
    client_completion_item_options_kind) noexcept -> void
    {
        if(object.contains("valueSet"))
        {
            client_completion_item_options_kind.valueSet = std::vector<CompletionItemKind>{};
            const nlohmann::json& valueSet = object.at("valueSet");
            for(const nlohmann::json& value : valueSet)
                client_completion_item_options_kind.valueSet->emplace_back(static_cast<
                CompletionItemKind>(value.get<std::uint8_t>()));
        }
    }

    auto to_json(nlohmann::json& object, const ClientCompletionItemOptionsKind&
    client_completion_item_options_kind) noexcept -> void
    {
        if(client_completion_item_options_kind.valueSet.has_value())
        {
            nlohmann::json valueSet = nlohmann::json::array();
            for(const CompletionItemKind value : *client_completion_item_options_kind.valueSet)
                valueSet.emplace_back(static_cast<std::uint8_t>(value));
            object["valueSet"] = valueSet;
        }
    }
}

#endif