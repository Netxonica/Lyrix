// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DiagnosticClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DiagnosticClientCapabilities&
    diagnostic_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            diagnostic_client_capabilities.dynamicRegistration = object.at("dynamicRegistration").
            get<bool>();
        if(object.contains("relatedDocumentSupport"))
            diagnostic_client_capabilities.relatedDocumentSupport = object.at(
            "relatedDocumentSupport").get<bool>();
        if(object.contains("relatedInformation"))
            diagnostic_client_capabilities.relatedInformation = object.at("relatedInformation").get
            <bool>();
        if(object.contains("tagSupport"))
            diagnostic_client_capabilities.tagSupport = object.at("tagSupport").get<
            ClientDiagnosticsTagOptions>();
        if(object.contains("codeDescriptionSupport"))
            diagnostic_client_capabilities.codeDescriptionSupport = object.at(
            "codeDescriptionSupport").get<bool>();
        if(object.contains("markupMessageSupport"))
            diagnostic_client_capabilities.markupMessageSupport = object.at("markupMessageSupport")
            .get<bool>();
        if(object.contains("dataSupport"))
            diagnostic_client_capabilities.dataSupport = object.at("dataSupport").get<bool>();
    }

    auto to_json(nlohmann::json& object, const DiagnosticClientCapabilities&
    diagnostic_client_capabilities) noexcept -> void
    {
        if(diagnostic_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *diagnostic_client_capabilities.dynamicRegistration;
        if(diagnostic_client_capabilities.relatedDocumentSupport.has_value())
            object["relatedDocumentSupport"] = *diagnostic_client_capabilities.
            relatedDocumentSupport;
        if(diagnostic_client_capabilities.relatedInformation.has_value())
            object["relatedInformation"] = *diagnostic_client_capabilities.relatedInformation;
        if(diagnostic_client_capabilities.tagSupport.has_value())
            object["tagSupport"] = *diagnostic_client_capabilities.tagSupport;
        if(diagnostic_client_capabilities.codeDescriptionSupport.has_value())
            object["codeDescriptionSupport"] = *diagnostic_client_capabilities.
            codeDescriptionSupport;
        if(diagnostic_client_capabilities.markupMessageSupport.has_value())
            object["markupMessageSupport"] = *diagnostic_client_capabilities.markupMessageSupport;
        if(diagnostic_client_capabilities.dataSupport.has_value())
            object["dataSupport"] = *diagnostic_client_capabilities.dataSupport;
    }
}

#endif