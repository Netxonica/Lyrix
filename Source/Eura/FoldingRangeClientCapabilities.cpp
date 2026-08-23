// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FoldingRangeClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, FoldingRangeClientCapabilities&
    folding_range_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            folding_range_client_capabilities.dynamicRegistration = object.at("dynamicRegistration"
            ).get<bool>();
        if(object.contains("rangeLimit"))
            folding_range_client_capabilities.rangeLimit = object.at("rangeLimit").get<std::
            uint32_t>();
        if(object.contains("lineFoldingOnly"))
            folding_range_client_capabilities.lineFoldingOnly = object.at("lineFoldingOnly").get<
            bool>();
        if(object.contains("foldingRangeKind"))
            folding_range_client_capabilities.foldingRangeKind = object.at("foldingRangeKind").get<
            ClientFoldingRangeKindOptions>();
        if(object.contains("foldingRange"))
            folding_range_client_capabilities.foldingRange = object.at("foldingRange").get<
            ClientFoldingRangeOptions>();
    }

    auto to_json(nlohmann::json& object, const FoldingRangeClientCapabilities&
    folding_range_client_capabilities) noexcept -> void
    {
        if(folding_range_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *folding_range_client_capabilities.dynamicRegistration;
        if(folding_range_client_capabilities.rangeLimit.has_value())
            object["rangeLimit"] = *folding_range_client_capabilities.rangeLimit;
        if(folding_range_client_capabilities.lineFoldingOnly.has_value())
            object["lineFoldingOnly"] = *folding_range_client_capabilities.lineFoldingOnly;
        if(folding_range_client_capabilities.foldingRangeKind.has_value())
            object["foldingRangeKind"] = *folding_range_client_capabilities.foldingRangeKind;
        if(folding_range_client_capabilities.foldingRange.has_value())
            object["foldingRange"] = *folding_range_client_capabilities.foldingRange;
    }
}

#endif