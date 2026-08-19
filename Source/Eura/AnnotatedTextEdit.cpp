// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/AnnotatedTextEdit.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, AnnotatedTextEdit& annotated_text_edit) noexcept
    -> void
    {
        from_json(object, static_cast<TextEdit&>(annotated_text_edit));
        annotated_text_edit.annotationId = object.at("annotationId").get<ChangeAnnotationIdentifier
        >();
    }

    auto to_json(nlohmann::json& object, const AnnotatedTextEdit& annotated_text_edit) noexcept ->
    void
    {
        to_json(object, static_cast<const TextEdit&>(annotated_text_edit));
        object["annotationId"] = annotated_text_edit.annotationId;
    }
}

#endif