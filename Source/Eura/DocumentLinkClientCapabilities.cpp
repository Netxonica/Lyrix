// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentLinkClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DocumentLinkClientCapabilities&
    document_link_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            document_link_client_capabilities.dynamicRegistration = object.at("dynamicRegistration"
            ).get<bool>();
        if(object.contains("tooltipSupport"))
            document_link_client_capabilities.tooltipSupport = object.at("tooltipSupport").get<bool
            >();
    }

    auto to_json(nlohmann::json& object, const DocumentLinkClientCapabilities&
    document_link_client_capabilities) noexcept -> void
    {
        if(document_link_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *document_link_client_capabilities.dynamicRegistration;
        if(document_link_client_capabilities.tooltipSupport.has_value())
            object["tooltipSupport"] = *document_link_client_capabilities.tooltipSupport;
    }
}

#endif