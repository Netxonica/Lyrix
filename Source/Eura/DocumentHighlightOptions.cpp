// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentHighlightOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DocumentHighlightOptions&
    document_highlight_options) noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressOptions&>(document_highlight_options));
    }

    auto to_json(nlohmann::json& object, const DocumentHighlightOptions& document_highlight_options
    ) noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressOptions&>(document_highlight_options));
    }
}

#endif