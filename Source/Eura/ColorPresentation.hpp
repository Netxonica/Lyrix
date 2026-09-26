// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_color_presentation
#define lyrix_header_guard_eura_color_presentation
#include "Eura/TextEdit.hpp"

namespace Eura
{
    struct [[nodiscard]] ColorPresentation final
    {
        std::string label;

        std::optional<TextEdit> textEdit;

        std::optional<std::vector<TextEdit>> additionalTextEdits;
    };

    auto from_json(const nlohmann::json& object, ColorPresentation& color_presentation) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const ColorPresentation& color_presentation) noexcept ->
    void;
}

#endif
#endif