// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ShowDocumentClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ShowDocumentClientCapabilities&
    show_document_client_capabilities) noexcept -> void
    {
        show_document_client_capabilities.support = object.at("support").get<bool>();
    }

    auto to_json(nlohmann::json& object, const ShowDocumentClientCapabilities&
    show_document_client_capabilities) noexcept -> void
    {
        object["support"] = show_document_client_capabilities.support;
    }
}

#endif