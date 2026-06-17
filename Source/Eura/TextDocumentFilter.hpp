// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_filter
#define lyrix_header_guard_eura_text_document_filter
#include "Eura/GlobPattern.hpp"

namespace Eura
{
    struct [[nodiscard]] TextDocumentFilter final
    {
        std::optional<Json::String> language, scheme;

        std::optional<GlobPattern> pattern;
    };

    auto Deserialize(const Json::Object& object, TextDocumentFilter& text_document_filter) noexcept
    -> void;

    auto Serialize(Json::Object& object, const TextDocumentFilter& text_document_filter) noexcept
    -> void;
}

#endif
#endif