// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentFilterClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TextDocumentFilterClientCapabilities&
    text_document_filter_client_capabilities) noexcept -> void
    {
        if(object.contains("relativePatternSupport"))
            text_document_filter_client_capabilities.relativePatternSupport = object.at(
            "relativePatternSupport").get<bool>();
    }

    auto to_json(nlohmann::json& object, const TextDocumentFilterClientCapabilities&
    text_document_filter_client_capabilities) noexcept -> void
    {
        if(text_document_filter_client_capabilities.relativePatternSupport.has_value())
            object["relativePatternSupport"] = *text_document_filter_client_capabilities.
            relativePatternSupport;
    }
}

#endif