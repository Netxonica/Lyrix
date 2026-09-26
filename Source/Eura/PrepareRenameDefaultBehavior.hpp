// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_prepare_rename_default_behavior
#define lyrix_header_guard_eura_prepare_rename_default_behavior
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] PrepareRenameDefaultBehavior final
    {
        bool defaultBehavior;
    };

    auto from_json(const nlohmann::json& object, PrepareRenameDefaultBehavior&
    prepare_rename_default_behavior) noexcept -> void;

    auto to_json(nlohmann::json& object, const PrepareRenameDefaultBehavior&
    prepare_rename_default_behavior) noexcept -> void;
}

#endif
#endif