// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentSaveRegistrationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TextDocumentSaveRegistrationOptions&
    text_document_save_registration_options) noexcept -> void
    {
        from_json(object, static_cast<TextDocumentRegistrationOptions&>(
        text_document_save_registration_options));
    }

    auto to_json(nlohmann::json& object, const TextDocumentSaveRegistrationOptions&
    text_document_save_registration_options) noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentRegistrationOptions&>(
        text_document_save_registration_options));
    }
}

#endif