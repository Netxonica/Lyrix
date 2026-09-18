// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_notebook_cell
#define lyrix_header_guard_eura_notebook_cell
#include "Eura/DocumentUri.hpp"
#include "Eura/NotebookCellKind.hpp"
#include "Eura/ExecutionSummary.hpp"

namespace Eura
{
    struct [[nodiscard]] NotebookCell final
    {
        NotebookCellKind kind;

        DocumentUri document;

        std::optional<nlohmann::json> metadata;

        std::optional<ExecutionSummary> executionSummary;
    };

    auto from_json(const nlohmann::json& object, NotebookCell& notebook_cell) noexcept -> void;

    auto to_json(nlohmann::json& object, const NotebookCell& notebook_cell) noexcept -> void;
}

#endif
#endif