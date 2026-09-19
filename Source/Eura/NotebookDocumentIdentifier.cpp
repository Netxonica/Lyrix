// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotebookDocumentIdentifier.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, NotebookDocumentIdentifier&
    notebook_document_identifier) noexcept -> void
    {
        notebook_document_identifier.uri = object.at("uri").get<URI>();
    }

    auto to_json(nlohmann::json& object, const NotebookDocumentIdentifier&
    notebook_document_identifier) noexcept -> void
    {
        object["uri"] = notebook_document_identifier.uri;
    }
}

#endif