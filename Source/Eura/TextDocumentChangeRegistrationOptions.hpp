// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_change_registration_options
#define lyrix_header_guard_eura_text_document_change_registration_options
#include "Eura/TextDocumentSyncKind.hpp"
#include "Eura/TextDocumentRegistrationOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] TextDocumentChangeRegistrationOptions final :
    TextDocumentRegistrationOptions
    {
        TextDocumentSyncKind syncKind;
    };

    auto from_json(const nlohmann::json& object, TextDocumentChangeRegistrationOptions&
    text_document_change_registration_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const TextDocumentChangeRegistrationOptions&
    text_document_change_registration_options) noexcept -> void;
}

#endif
#endif