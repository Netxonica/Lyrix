// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_document_on_type_formatting_client_capabilities
#define lyrix_header_guard_eura_document_on_type_formatting_client_capabilities
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] DocumentOnTypeFormattingClientCapabilities final
    {
        std::optional<bool> dynamicRegistration;
    };

    auto from_json(const nlohmann::json& object, DocumentOnTypeFormattingClientCapabilities&
    document_on_type_formatting_client_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const DocumentOnTypeFormattingClientCapabilities&
    document_on_type_formatting_client_capabilities) noexcept -> void;
}

#endif
#endif