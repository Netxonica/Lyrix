// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentContentParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TextDocumentContentParams&
    text_document_content_params) noexcept -> void
    {
        text_document_content_params.uri = object.at("uri").get<DocumentUri>();
    }

    auto to_json(nlohmann::json& object, const TextDocumentContentParams&
    text_document_content_params) noexcept -> void
    {
        object["uri"] = text_document_content_params.uri;
    }
}

#endif