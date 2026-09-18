// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_notebook_cell_array_change
#define lyrix_header_guard_eura_notebook_cell_array_change
#include "Eura/NotebookCell.hpp"

namespace Eura
{
    struct [[nodiscard]] NotebookCellArrayChange final
    {
        std::uint32_t start, deleteCount;

        std::optional<std::vector<NotebookCell>> cells;
    };

    auto from_json(const nlohmann::json& object, NotebookCellArrayChange&
    notebook_cell_array_change) noexcept -> void;

    auto to_json(nlohmann::json& object, const NotebookCellArrayChange& notebook_cell_array_change)
    noexcept -> void;
}

#endif
#endif