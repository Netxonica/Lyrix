// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_completion_params
#define lyrix_header_guard_eura_completion_params
#include "Eura/CompletionContext.hpp"
#include "Eura/PartialResultParams.hpp"
#include "Eura/WorkDoneProgressParams.hpp"
#include "Eura/TextDocumentPositionParams.hpp"

namespace Eura
{
    struct [[nodiscard]] CompletionParams final : TextDocumentPositionParams,
    WorkDoneProgressParams, PartialResultParams
    {
        std::optional<CompletionContext> context;
    };

    auto from_json(const nlohmann::json& object, CompletionParams& completion_params) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const CompletionParams& completion_params) noexcept ->
    void;
}

#endif
#endif