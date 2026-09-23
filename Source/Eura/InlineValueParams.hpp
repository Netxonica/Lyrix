// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_inline_value_params
#define lyrix_header_guard_eura_inline_value_params
#include "Eura/InlineValueContext.hpp"
#include "Eura/TextDocumentIdentifier.hpp"
#include "Eura/WorkDoneProgressParams.hpp"

namespace Eura
{
    struct [[nodiscard]] InlineValueParams final : WorkDoneProgressParams
    {
        TextDocumentIdentifier textDocument;

        Range range;

        InlineValueContext context;
    };

    auto from_json(const nlohmann::json& object, InlineValueParams& inline_value_params) noexcept
    -> void;

    auto to_json(nlohmann::json& object, const InlineValueParams& inline_value_params) noexcept ->
    void;
}

#endif
#endif