// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_document_highlight
#define lyrix_header_guard_eura_document_highlight
#include "Eura/Range.hpp"
#include "Eura/DocumentHighlightKind.hpp"

namespace Eura
{
    struct [[nodiscard]] DocumentHighlight final
    {
        Range range;

        std::optional<DocumentHighlightKind> kind;
    };

    auto from_json(const nlohmann::json& object, DocumentHighlight& document_highlight) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const DocumentHighlight& document_highlight) noexcept ->
    void;
}

#endif
#endif