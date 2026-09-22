// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_code_lens_params
#define lyrix_header_guard_eura_code_lens_params
#include "Eura/PartialResultParams.hpp"
#include "Eura/TextDocumentIdentifier.hpp"
#include "Eura/WorkDoneProgressParams.hpp"

namespace Eura
{
    struct [[nodiscard]] CodeLensParams final : WorkDoneProgressParams, PartialResultParams
    {
        TextDocumentIdentifier textDocument;
    };

    auto from_json(const nlohmann::json& object, CodeLensParams& code_lens_params) noexcept -> void
    ;

    auto to_json(nlohmann::json& object, const CodeLensParams& code_lens_params) noexcept -> void;
}

#endif
#endif