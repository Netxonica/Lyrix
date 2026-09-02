// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotebookCellLanguage.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, NotebookCellLanguage& notebook_cell_language)
    noexcept -> void
    {
        notebook_cell_language.language = object.at("language").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const NotebookCellLanguage& notebook_cell_language)
    noexcept -> void
    {
        object["language"] = notebook_cell_language.language;
    }
}

#endif