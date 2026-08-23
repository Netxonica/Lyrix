// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientCodeActionKindOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ClientCodeActionKindOptions&
    client_code_action_kind_options) noexcept -> void
    {
        const nlohmann::json& valueSet = object.at("valueSet");
        for(const nlohmann::json& value : valueSet)
            client_code_action_kind_options.valueSet.emplace_back(value.get<CodeActionKind>());
    }

    auto to_json(nlohmann::json& object, const ClientCodeActionKindOptions&
    client_code_action_kind_options) noexcept -> void
    {
        nlohmann::json valueSet = nlohmann::json::array();
        for(const CodeActionKind& value : client_code_action_kind_options.valueSet)
            valueSet.emplace_back(value);
        object["valueSet"] = valueSet;
    }
}

#endif