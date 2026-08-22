// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_change_annotations_support_options
#define lyrix_header_guard_eura_change_annotations_support_options
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] ChangeAnnotationsSupportOptions final
    {
        std::optional<bool> groupsOnLabel;
    };

    auto from_json(const nlohmann::json& object, ChangeAnnotationsSupportOptions&
    change_annotations_support_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const ChangeAnnotationsSupportOptions&
    change_annotations_support_options) noexcept -> void;
}

#endif
#endif