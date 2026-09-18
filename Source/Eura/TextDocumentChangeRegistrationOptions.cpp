// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentChangeRegistrationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TextDocumentChangeRegistrationOptions&
    text_document_change_registration_options) noexcept -> void
    {
        from_json(object, static_cast<TextDocumentRegistrationOptions&>(
        text_document_change_registration_options));
        text_document_change_registration_options.syncKind = object.at("syncKind").get<
        TextDocumentSyncKind>();
    }

    auto to_json(nlohmann::json& object, const TextDocumentChangeRegistrationOptions&
    text_document_change_registration_options) noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentRegistrationOptions&>(
        text_document_change_registration_options));
        object["syncKind"] = text_document_change_registration_options.syncKind;
    }
}

#endif