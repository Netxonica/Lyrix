// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentContentRegistrationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TextDocumentContentRegistrationOptions&
    text_document_content_registration_options) noexcept -> void
    {
        from_json(object, static_cast<TextDocumentContentOptions&>(
        text_document_content_registration_options));
        from_json(object, static_cast<StaticRegistrationOptions&>(
        text_document_content_registration_options));
    }

    auto to_json(nlohmann::json& object, const TextDocumentContentRegistrationOptions&
    text_document_content_registration_options) noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentContentOptions&>(
        text_document_content_registration_options));
        to_json(object, static_cast<const StaticRegistrationOptions&>(
        text_document_content_registration_options));
    }
}

#endif