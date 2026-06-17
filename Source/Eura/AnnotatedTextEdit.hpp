// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_annotated_text_edit
#define lyrix_header_guard_eura_annotated_text_edit
#include "Eura/TextEdit.hpp"
#include "Eura/ChangeAnnotationIdentifier.hpp"

namespace Eura
{
    struct [[nodiscard]] AnnotatedTextEdit final : public TextEdit
    {
        ChangeAnnotationIdentifier annotationId;
    };

    auto Deserialize(const Json::Object& object, AnnotatedTextEdit& annotated_text_edit) noexcept
    -> void;

    auto Serialize(Json::Object& object, const AnnotatedTextEdit& annotated_text_edit) noexcept ->
    void;
}

#endif
#endif