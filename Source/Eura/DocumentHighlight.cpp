// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentHighlight.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DocumentHighlight& document_highlight) noexcept ->
    void
    {
        document_highlight.range = object.at("range").get<Range>();
        if(object.contains("kind"))
            document_highlight.kind = object.at("kind").get<DocumentHighlightKind>();
    }

    auto to_json(nlohmann::json& object, const DocumentHighlight& document_highlight) noexcept ->
    void
    {
        object["range"] = document_highlight.range;
        if(document_highlight.kind.has_value())
            object["kind"] = *document_highlight.kind;
    }
}

#endif