// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentContentRefreshParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TextDocumentContentRefreshParams&
    text_document_content_refresh_params) noexcept -> void
    {
        text_document_content_refresh_params.uri = object.at("uri").get<DocumentUri>();
    }

    auto to_json(nlohmann::json& object, const TextDocumentContentRefreshParams&
    text_document_content_refresh_params) noexcept -> void
    {
        object["uri"] = text_document_content_refresh_params.uri;
    }
}

#endif