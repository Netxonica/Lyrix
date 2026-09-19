// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_notebook_document_change_event
#define lyrix_header_guard_eura_notebook_document_change_event
#include "Eura/NotebookDocumentCellChanges.hpp"

namespace Eura
{
    struct [[nodiscard]] NotebookDocumentChangeEvent final
    {
        std::optional<nlohmann::json> metadata;

        std::optional<NotebookDocumentCellChanges> cells;
    };

    auto from_json(const nlohmann::json& object, NotebookDocumentChangeEvent&
    notebook_document_change_event) noexcept -> void;

    auto to_json(nlohmann::json& object, const NotebookDocumentChangeEvent&
    notebook_document_change_event) noexcept -> void;
}

#endif
#endif