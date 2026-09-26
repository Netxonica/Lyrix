// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_document_on_type_formatting_params
#define lyrix_header_guard_eura_document_on_type_formatting_params
#include "Eura/Position.hpp"
#include "Eura/FormattingOptions.hpp"
#include "Eura/TextDocumentIdentifier.hpp"

namespace Eura
{
    struct [[nodiscard]] DocumentOnTypeFormattingParams final
    {
        TextDocumentIdentifier textDocument;

        Position position;

        std::string ch;

        FormattingOptions options;
    };

    auto from_json(const nlohmann::json& object, DocumentOnTypeFormattingParams&
    document_on_type_formatting_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const DocumentOnTypeFormattingParams&
    document_on_type_formatting_params) noexcept -> void;
}

#endif
#endif