// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_document_link_params
#define lyrix_header_guard_eura_document_link_params
#include "Eura/PartialResultParams.hpp"
#include "Eura/TextDocumentIdentifier.hpp"
#include "Eura/WorkDoneProgressParams.hpp"

namespace Eura
{
    struct [[nodiscard]] DocumentLinkParams final : WorkDoneProgressParams, PartialResultParams
    {
        TextDocumentIdentifier textDocument;
    };

    auto from_json(const nlohmann::json& object, DocumentLinkParams& document_link_params) noexcept
    -> void;

    auto to_json(nlohmann::json& object, const DocumentLinkParams& document_link_params) noexcept
    -> void;
}

#endif
#endif