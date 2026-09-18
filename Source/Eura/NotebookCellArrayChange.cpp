// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotebookCellArrayChange.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, NotebookCellArrayChange&
    notebook_cell_array_change) noexcept -> void
    {
        notebook_cell_array_change.start = object.at("start").get<std::uint32_t>();
        notebook_cell_array_change.deleteCount = object.at("deleteCount").get<std::uint32_t>();
        if(object.contains("cells"))
        {
            notebook_cell_array_change.cells = std::vector<NotebookCell>{};
            const nlohmann::json& cells = object.at("cells");
            for(const nlohmann::json& cell : cells)
                notebook_cell_array_change.cells->emplace_back(cell.get<NotebookCell>());
        }
    }

    auto to_json(nlohmann::json& object, const NotebookCellArrayChange& notebook_cell_array_change)
    noexcept -> void
    {
        object["start"] = notebook_cell_array_change.start;
        object["deleteCount"] = notebook_cell_array_change.deleteCount;
        if(notebook_cell_array_change.cells.has_value())
        {
            nlohmann::json cells = nlohmann::json::array();
            for(const NotebookCell& cell : *notebook_cell_array_change.cells)
                cells.emplace_back(cell);
            object["cells"] = cells;
        }
    }
}

#endif