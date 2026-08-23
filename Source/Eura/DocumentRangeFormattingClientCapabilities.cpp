// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentRangeFormattingClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DocumentRangeFormattingClientCapabilities&
    document_range_formatting_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            document_range_formatting_client_capabilities.dynamicRegistration = object.at(
            "dynamicRegistration").get<bool>();
        if(object.contains("rangesSupport"))
            document_range_formatting_client_capabilities.rangesSupport = object.at("rangesSupport"
            ).get<bool>();
    }

    auto to_json(nlohmann::json& object, const DocumentRangeFormattingClientCapabilities&
    document_range_formatting_client_capabilities) noexcept -> void
    {
        if(document_range_formatting_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *document_range_formatting_client_capabilities.
            dynamicRegistration;
        if(document_range_formatting_client_capabilities.rangesSupport.has_value())
            object["rangesSupport"] = *document_range_formatting_client_capabilities.rangesSupport;
    }
}

#endif