// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_inlay_hint_label_part
#define lyrix_header_guard_eura_inlay_hint_label_part
#include "Eura/Command.hpp"
#include "Eura/Location.hpp"
#include "Eura/MarkupContent.hpp"

namespace Eura
{
    struct [[nodiscard]] InlayHintLabelPart final
    {
        std::string value;

        std::optional<std::variant<std::string, MarkupContent>> tooltip;

        std::optional<Location> location;

        std::optional<Command> command;
    };

    auto from_json(const nlohmann::json& object, InlayHintLabelPart& inlay_hint_label_part)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const InlayHintLabelPart& inlay_hint_label_part) noexcept
    -> void;
}

#endif
#endif