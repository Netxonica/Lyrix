// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_rename_params
#define lyrix_header_guard_eura_rename_params
#include "Eura/WorkDoneProgressParams.hpp"
#include "Eura/TextDocumentPositionParams.hpp"

namespace Eura
{
    struct [[nodiscard]] RenameParams final : TextDocumentPositionParams, WorkDoneProgressParams
    {
        std::string newName;
    };

    auto from_json(const nlohmann::json& object, RenameParams& rename_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const RenameParams& rename_params) noexcept -> void;
}

#endif
#endif