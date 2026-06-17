// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_position_params
#define lyrix_header_guard_eura_text_document_position_params
#include "Eura/Position.hpp"
#include "Eura/TextDocumentIdentifier.hpp"

namespace Eura
{
    struct [[nodiscard]] TextDocumentPositionParams final
    {
        TextDocumentIdentifier textDocument;

        Position position;
    };

    auto Deserialize(const Json::Object& object, TextDocumentPositionParams&
    text_document_position_params) noexcept -> void;

    auto Serialize(Json::Object& object, const TextDocumentPositionParams&
    text_document_position_params) noexcept -> void;
}

#endif
#endif