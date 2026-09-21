// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentHighlightParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DocumentHighlightParams& document_highlight_params
    ) noexcept -> void
    {
        from_json(object, static_cast<TextDocumentPositionParams&>(document_highlight_params));
        from_json(object, static_cast<WorkDoneProgressParams&>(document_highlight_params));
        from_json(object, static_cast<PartialResultParams&>(document_highlight_params));
    }

    auto to_json(nlohmann::json& object, const DocumentHighlightParams& document_highlight_params)
    noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentPositionParams&>(document_highlight_params));
        to_json(object, static_cast<const WorkDoneProgressParams&>(document_highlight_params));
        to_json(object, static_cast<const PartialResultParams&>(document_highlight_params));
    }
}

#endif