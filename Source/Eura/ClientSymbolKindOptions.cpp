// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientSymbolKindOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ClientSymbolKindOptions&
    client_symbol_kind_options) noexcept -> void
    {
        if(object.contains("valueSet"))
        {
            client_symbol_kind_options.valueSet = std::vector<SymbolKind>{};
            const nlohmann::json& valueSet = object.at("valueSet");
            for(const nlohmann::json& value : valueSet)
                client_symbol_kind_options.valueSet->emplace_back(static_cast<SymbolKind>(value.get
                <std::uint8_t>()));
        }
    }

    auto to_json(nlohmann::json& object, const ClientSymbolKindOptions& client_symbol_kind_options)
    noexcept -> void
    {
        if(client_symbol_kind_options.valueSet.has_value())
        {
            nlohmann::json valueSet = nlohmann::json::array();
            for(const SymbolKind value : *client_symbol_kind_options.valueSet)
                valueSet.emplace_back(static_cast<std::uint8_t>(value));
            object["valueSet"] = valueSet;
        }
    }
}

#endif