// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_notebook_document
#define lyrix_header_guard_eura_notebook_document
#include "Eura/URI.hpp"
#include "Eura/NotebookCell.hpp"

namespace Eura
{
    struct [[nodiscard]] NotebookDocument final
    {
        URI uri;

        std::string notebookType;

        std::int32_t version;

        std::optional<nlohmann::json> metadata;

        std::vector<NotebookCell> cells;
    };

    auto from_json(const nlohmann::json& object, NotebookDocument& notebook_document) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const NotebookDocument& notebook_document) noexcept ->
    void;
}

#endif
#endif