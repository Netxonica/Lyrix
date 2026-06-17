// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_snippet_text_edit
#define lyrix_header_guard_eura_snippet_text_edit
#include "Eura/Range.hpp"
#include "Eura/StringValue.hpp"
#include "Eura/ChangeAnnotationIdentifier.hpp"

namespace Eura
{
    struct [[nodiscard]] SnippetTextEdit final
    {
        Range range;

        StringValue snippet;

        std::optional<ChangeAnnotationIdentifier> annotationId;
    };

    auto Deserialize(const Json::Object& object, SnippetTextEdit& snippet_text_edit) noexcept ->
    void;

    auto Serialize(Json::Object& object, const SnippetTextEdit& snippet_text_edit) noexcept -> void
    ;
}

#endif
#endif