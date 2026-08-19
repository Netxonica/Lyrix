// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_change_annotation
#define lyrix_header_guard_eura_change_annotation
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] ChangeAnnotation final
    {
        std::string label;

        std::optional<bool> needsConfirmation;

        std::optional<std::string> description;
    };

    auto from_json(const nlohmann::json& object, ChangeAnnotation& change_annotation) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const ChangeAnnotation& change_annotation) noexcept ->
    void;
}

#endif
#endif