// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_document_highlight_options
#define lyrix_header_guard_eura_document_highlight_options
#include "Eura/WorkDoneProgressOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] DocumentHighlightOptions final : WorkDoneProgressOptions{};

    auto from_json(const nlohmann::json& object, DocumentHighlightOptions&
    document_highlight_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const DocumentHighlightOptions& document_highlight_options
    ) noexcept -> void;
}

#endif
#endif