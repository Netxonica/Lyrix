// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_reference_params
#define lyrix_header_guard_eura_reference_params
#include "Eura/ReferenceContext.hpp"
#include "Eura/PartialResultParams.hpp"
#include "Eura/WorkDoneProgressParams.hpp"
#include "Eura/TextDocumentPositionParams.hpp"

namespace Eura
{
    struct [[nodiscard]] ReferenceParams final : TextDocumentPositionParams,
    WorkDoneProgressParams, PartialResultParams
    {
        ReferenceContext context;
    };

    auto from_json(const nlohmann::json& object, ReferenceParams& reference_params) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const ReferenceParams& reference_params) noexcept -> void;
}

#endif
#endif