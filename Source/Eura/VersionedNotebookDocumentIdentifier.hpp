// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_versioned_notebook_document_identifier
#define lyrix_header_guard_eura_versioned_notebook_document_identifier
#include "Eura/URI.hpp"
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] VersionedNotebookDocumentIdentifier final
    {
        std::int32_t version;
        
        URI uri;
    };

    auto from_json(const nlohmann::json& object, VersionedNotebookDocumentIdentifier&
    versioned_notebook_document_identifier) noexcept -> void;

    auto to_json(nlohmann::json& object, const VersionedNotebookDocumentIdentifier&
    versioned_notebook_document_identifier) noexcept -> void;
}

#endif
#endif