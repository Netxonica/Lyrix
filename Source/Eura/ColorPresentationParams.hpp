// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_color_presentation_params
#define lyrix_header_guard_eura_color_presentation_params
#include "Eura/Color.hpp"
#include "Eura/Range.hpp"
#include "Eura/PartialResultParams.hpp"
#include "Eura/TextDocumentIdentifier.hpp"
#include "Eura/WorkDoneProgressParams.hpp"

namespace Eura
{
    struct [[nodiscard]] ColorPresentationParams final : WorkDoneProgressParams,
    PartialResultParams
    {
        TextDocumentIdentifier textDocument;

        Color color;

        Range range;
    };

    auto from_json(const nlohmann::json& object, ColorPresentationParams& color_presentation_params
    ) noexcept -> void;

    auto to_json(nlohmann::json& object, const ColorPresentationParams& color_presentation_params)
    noexcept -> void;
}

#endif
#endif