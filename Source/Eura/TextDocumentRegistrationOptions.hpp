// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_registration_options
#define lyrix_header_guard_eura_text_document_registration_options
#include "Eura/DocumentSelector.hpp"

namespace Eura
{
    struct [[nodiscard]] TextDocumentRegistrationOptions
    {
        std::variant<DocumentSelector, std::nullptr_t> documentSelector;
    };

    auto from_json(const nlohmann::json& object, TextDocumentRegistrationOptions&
    text_document_registration_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const TextDocumentRegistrationOptions&
    text_document_registration_options) noexcept -> void;
}

#endif
#endif