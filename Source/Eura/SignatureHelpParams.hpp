// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_signature_help_params
#define lyrix_header_guard_eura_signature_help_params
#include "Eura/SignatureHelpContext.hpp"
#include "Eura/WorkDoneProgressParams.hpp"
#include "Eura/TextDocumentPositionParams.hpp"

namespace Eura
{
    struct [[nodiscard]] SignatureHelpParams final : TextDocumentPositionParams,
    WorkDoneProgressParams
    {
        std::optional<SignatureHelpContext> context;
    };

    auto from_json(const nlohmann::json& object, SignatureHelpParams& signature_help_params)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const SignatureHelpParams& signature_help_params) noexcept
    -> void;
}

#endif
#endif