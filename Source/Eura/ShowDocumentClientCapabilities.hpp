// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_show_document_client_capabilities
#define lyrix_header_guard_eura_show_document_client_capabilities
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] ShowDocumentClientCapabilities final
    {
        bool support;
    };

    auto from_json(const nlohmann::json& object, ShowDocumentClientCapabilities&
    show_document_client_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const ShowDocumentClientCapabilities&
    show_document_client_capabilities) noexcept -> void;
}

#endif
#endif