// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SnippetTextEdit.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SnippetTextEdit& snippet_text_edit) noexcept ->
    void
    {
        snippet_text_edit.range = object.at("range").get<Range>();
        snippet_text_edit.snippet = object.at("snippet").get<StringValue>();
        if(object.contains("annotationId"))
            snippet_text_edit.annotationId = object.at("annotationId").get<
            ChangeAnnotationIdentifier>();
    }

    auto to_json(nlohmann::json& object, const SnippetTextEdit& snippet_text_edit) noexcept -> void
    {
        object["range"] = snippet_text_edit.range;
        object["snippet"] = snippet_text_edit.snippet;
        if(snippet_text_edit.annotationId.has_value())
            object["annotationId"] = *snippet_text_edit.annotationId;
    }
}

#endif