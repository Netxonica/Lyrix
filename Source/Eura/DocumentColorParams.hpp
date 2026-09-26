// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_document_color_params
#define lyrix_header_guard_eura_document_color_params
#include "Eura/PartialResultParams.hpp"
#include "Eura/TextDocumentIdentifier.hpp"
#include "Eura/WorkDoneProgressParams.hpp"

namespace Eura
{
    struct [[nodiscard]] DocumentColorParams final : WorkDoneProgressParams, PartialResultParams
    {
        TextDocumentIdentifier textDocument;
    };

    auto from_json(const nlohmann::json& object, DocumentColorParams& document_color_params)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const DocumentColorParams& document_color_params) noexcept
    -> void;
}

#endif
#endif