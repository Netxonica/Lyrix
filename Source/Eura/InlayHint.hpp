// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_inlay_hint
#define lyrix_header_guard_eura_inlay_hint
#include "Eura/TextEdit.hpp"
#include "Eura/InlayHintKind.hpp"
#include "Eura/InlayHintLabelPart.hpp"

namespace Eura
{
    struct [[nodiscard]] InlayHint final
    {
        Position position;

        std::variant<std::string, std::vector<InlayHintLabelPart>> label;

        std::optional<InlayHintKind> kind;

        std::optional<std::vector<TextEdit>> textEdits;

        std::optional<std::variant<std::string, MarkupContent>> tooltip;

        std::optional<bool> paddingLeft, paddingRight;

        std::optional<nlohmann::json> data;
    };

    auto from_json(const nlohmann::json& object, InlayHint& inlay_hint) noexcept -> void;

    auto to_json(nlohmann::json& object, const InlayHint& inlay_hint) noexcept -> void;
}

#endif
#endif