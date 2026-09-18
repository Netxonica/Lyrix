// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_save_registration_options
#define lyrix_header_guard_eura_text_document_save_registration_options
#include "Eura/TextDocumentRegistrationOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] TextDocumentSaveRegistrationOptions final :
    TextDocumentRegistrationOptions
    {};

    auto from_json(const nlohmann::json& object, TextDocumentSaveRegistrationOptions&
    text_document_save_registration_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const TextDocumentSaveRegistrationOptions&
    text_document_save_registration_options) noexcept -> void;
}

#endif
#endif