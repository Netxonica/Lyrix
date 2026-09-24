// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_document_diagnostic_params
#define lyrix_header_guard_eura_document_diagnostic_params
#include "Eura/PartialResultParams.hpp"
#include "Eura/WorkDoneProgressParams.hpp"
#include "Eura/TextDocumentIdentifier.hpp"

namespace Eura
{
    struct [[nodiscard]] DocumentDiagnosticParams final : WorkDoneProgressParams,
    PartialResultParams
    {
        TextDocumentIdentifier textDocument;

        std::optional<std::string> identifier, previousResultId;
    };

    auto from_json(const nlohmann::json& object, DocumentDiagnosticParams&
    document_diagnostic_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const DocumentDiagnosticParams& document_diagnostic_params
    ) noexcept -> void;
}

#endif
#endif