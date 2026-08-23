// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/PublishDiagnosticsClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, PublishDiagnosticsClientCapabilities&
    publish_diagnostics_client_capabilities) noexcept -> void
    {
        if(object.contains("relatedInformation"))
            publish_diagnostics_client_capabilities.relatedInformation = object.at(
            "relatedInformation").get<bool>();
        if(object.contains("tagSupport"))
            publish_diagnostics_client_capabilities.tagSupport = object.at("tagSupport").get<
            ClientDiagnosticsTagOptions>();
        if(object.contains("versionSupport"))
            publish_diagnostics_client_capabilities.versionSupport = object.at("versionSupport").
            get<bool>();
        if(object.contains("codeDescriptionSupport"))
            publish_diagnostics_client_capabilities.codeDescriptionSupport = object.at(
            "codeDescriptionSupport").get<bool>();
        if(object.contains("dataSupport"))
            publish_diagnostics_client_capabilities.dataSupport = object.at("dataSupport").get<bool
            >();
    }

    auto to_json(nlohmann::json& object, const PublishDiagnosticsClientCapabilities&
    publish_diagnostics_client_capabilities) noexcept -> void
    {
        if(publish_diagnostics_client_capabilities.relatedInformation.has_value())
            object["relatedInformation"] = *publish_diagnostics_client_capabilities.
            relatedInformation;
        if(publish_diagnostics_client_capabilities.tagSupport.has_value())
            object["tagSupport"] = *publish_diagnostics_client_capabilities.tagSupport;
        if(publish_diagnostics_client_capabilities.versionSupport.has_value())
            object["versionSupport"] = *publish_diagnostics_client_capabilities.versionSupport;
        if(publish_diagnostics_client_capabilities.codeDescriptionSupport.has_value())
            object["codeDescriptionSupport"] = *publish_diagnostics_client_capabilities.
            codeDescriptionSupport;
        if(publish_diagnostics_client_capabilities.dataSupport.has_value())
            object["dataSupport"] = *publish_diagnostics_client_capabilities.dataSupport;
    }
}

#endif