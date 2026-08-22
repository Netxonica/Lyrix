// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_document_symbol_client_capabilities
#define lyrix_header_guard_eura_document_symbol_client_capabilities
#include "Eura/ClientSymbolTagOptions.hpp"
#include "Eura/ClientSymbolKindOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] DocumentSymbolClientCapabilities final
    {
        std::optional<bool> dynamicRegistration;
    };

    auto from_json(const nlohmann::json& object, DocumentSymbolClientCapabilities&
    document_symbol_client_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const DocumentSymbolClientCapabilities&
    document_symbol_client_capabilities) noexcept -> void;
}

#endif
#endif