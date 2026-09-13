// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_rename_options
#define lyrix_header_guard_eura_rename_options
#include "Eura/WorkDoneProgressOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] RenameOptions final : WorkDoneProgressOptions
    {
        std::optional<bool> prepareProvider;
    };

    auto from_json(const nlohmann::json& object, RenameOptions& rename_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const RenameOptions& rename_options) noexcept -> void;
}

#endif
#endif