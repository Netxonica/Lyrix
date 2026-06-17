// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SnippetTextEdit.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, SnippetTextEdit& snippet_text_edit) noexcept ->
    void
    {
        Deserialize(object.Retrieve("range").As<Json::Object>(), snippet_text_edit.range);
        Deserialize(object.Retrieve("snippet").As<Json::Object>(), snippet_text_edit.snippet);
        if(object.Contains("annotationId"))
            snippet_text_edit.annotationId = object.Retrieve("annotationId").As<
            ChangeAnnotationIdentifier>();
    }

    auto Serialize(Json::Object& object, const SnippetTextEdit& snippet_text_edit) noexcept -> void
    {
        Serialize(object.NestedObject("range"), snippet_text_edit.range);
        Serialize(object.NestedObject("snippet"), snippet_text_edit.snippet);
        if(snippet_text_edit.annotationId.has_value())
            object.fields.emplace_back("annotationId", *snippet_text_edit.annotationId);
    }
}

#endif