// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_document_range_formatting_params
#define lyrix_header_guard_eura_document_range_formatting_params
#include "Eura/Range.hpp"
#include "Eura/FormattingOptions.hpp"
#include "Eura/TextDocumentIdentifier.hpp"
#include "Eura/WorkDoneProgressParams.hpp"

namespace Eura
{
    struct [[nodiscard]] DocumentRangeFormattingParams final : WorkDoneProgressParams
    {
        TextDocumentIdentifier textDocument;

        Range range;

        FormattingOptions options;
    };

    auto from_json(const nlohmann::json& object, DocumentRangeFormattingParams&
    document_range_formatting_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const DocumentRangeFormattingParams&
    document_range_formatting_params) noexcept -> void;
}

#endif
#endif