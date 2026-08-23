// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientFoldingRangeOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ClientFoldingRangeOptions&
    client_folding_range_options) noexcept -> void
    {
        if(object.contains("collapsedText"))
            client_folding_range_options.collapsedText = object.at("collapsedText").get<bool>();
    }

    auto to_json(nlohmann::json& object, const ClientFoldingRangeOptions&
    client_folding_range_options) noexcept -> void
    {
        if(client_folding_range_options.collapsedText.has_value())
            object["collapsedText"] = *client_folding_range_options.collapsedText;
    }
}

#endif