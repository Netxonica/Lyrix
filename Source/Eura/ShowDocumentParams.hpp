// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_show_document_params
#define lyrix_header_guard_eura_show_document_params
#include "Eura/URI.hpp"
#include "Eura/Range.hpp"

namespace Eura
{
    struct [[nodiscard]] ShowDocumentParams final
    {
        URI uri;

        std::optional<bool> external, takeFocus;

        std::optional<Range> selection;
    };

    auto from_json(const nlohmann::json& object, ShowDocumentParams& show_document_params) noexcept
    -> void;

    auto to_json(nlohmann::json& object, const ShowDocumentParams& show_document_params) noexcept
    -> void;
}

#endif
#endif