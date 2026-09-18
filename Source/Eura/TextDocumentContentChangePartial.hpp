// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_content_change_partial
#define lyrix_header_guard_eura_text_document_content_change_partial
#include "Eura/Range.hpp"

namespace Eura
{
    struct [[nodiscard]] TextDocumentContentChangePartial final
    {
        Range range;

        std::optional<std::uint32_t> rangeLength;

        std::string text;
    };

    auto from_json(const nlohmann::json& object, TextDocumentContentChangePartial&
    text_document_content_change_partial) noexcept -> void;

    auto to_json(nlohmann::json& object, const TextDocumentContentChangePartial&
    text_document_content_change_partial) noexcept -> void;
}

#endif
#endif