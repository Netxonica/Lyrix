// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_notebook_cell_language
#define lyrix_header_guard_eura_notebook_cell_language
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] NotebookCellLanguage final
    {
        std::string language;
    };

    auto from_json(const nlohmann::json& object, NotebookCellLanguage& notebook_cell_language)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const NotebookCellLanguage& notebook_cell_language)
    noexcept -> void;
}

#endif
#endif