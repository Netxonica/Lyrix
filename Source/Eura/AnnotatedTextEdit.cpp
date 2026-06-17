// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/AnnotatedTextEdit.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, AnnotatedTextEdit& annotated_text_edit) noexcept
    -> void
    {
        Deserialize(object, static_cast<TextEdit&>(annotated_text_edit));
        annotated_text_edit.annotationId = object.Retrieve("annotationId").As<Json::String>();
    }

    auto Serialize(Json::Object& object, const AnnotatedTextEdit& annotated_text_edit) noexcept ->
    void
    {
        Serialize(object, static_cast<const TextEdit&>(annotated_text_edit));
        object.fields.emplace_back("annotationId", annotated_text_edit.annotationId);
    }
}

#endif