// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/VersionedNotebookDocumentIdentifier.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, VersionedNotebookDocumentIdentifier&
    versioned_notebook_document_identifier) noexcept -> void
    {
        versioned_notebook_document_identifier.version = object.at("version").get<std::int32_t>();
        versioned_notebook_document_identifier.uri = object.at("uri").get<URI>();
    }

    auto to_json(nlohmann::json& object, const VersionedNotebookDocumentIdentifier&
    versioned_notebook_document_identifier) noexcept -> void
    {
        object["version"] = versioned_notebook_document_identifier.version;
        object["uri"] = versioned_notebook_document_identifier.uri;
    }
}

#endif