// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_prepare_rename_placeholder
#define lyrix_header_guard_eura_prepare_rename_placeholder
#include "Eura/Range.hpp"

namespace Eura
{
    struct [[nodiscard]] PrepareRenamePlaceholder final
    {
        Range range;

        std::string placeholder;
    };

    auto from_json(const nlohmann::json& object, PrepareRenamePlaceholder&
    prepare_rename_placeholder) noexcept -> void;

    auto to_json(nlohmann::json& object, const PrepareRenamePlaceholder& prepare_rename_placeholder
    ) noexcept -> void;
}

#endif
#endif