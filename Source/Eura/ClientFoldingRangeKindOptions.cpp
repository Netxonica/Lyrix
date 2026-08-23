// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientFoldingRangeKindOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ClientFoldingRangeKindOptions& 
    client_folding_range_kind_options) noexcept -> void
    {
        if(object.contains("valueSet"))
        {
            client_folding_range_kind_options.valueSet = std::vector<FoldingRangeKind>{};
            const nlohmann::json& valueSet = object.at("valueSet");
            for(const nlohmann::json& value : valueSet)
                client_folding_range_kind_options.valueSet->emplace_back(value.get<FoldingRangeKind
                >());
        }
    }

    auto to_json(nlohmann::json& object, const ClientFoldingRangeKindOptions&
    client_folding_range_kind_options) noexcept -> void
    {
        if(client_folding_range_kind_options.valueSet.has_value())
        {
            nlohmann::json valueSet = nlohmann::json::array();
            for(const FoldingRangeKind& value : *client_folding_range_kind_options.valueSet)
                valueSet.emplace_back(value);
            object["valueSet"] = valueSet;
        }
    }
}

#endif