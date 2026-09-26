// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_prepare_rename_params
#define lyrix_header_guard_eura_prepare_rename_params
#include "Eura/WorkDoneProgressParams.hpp"
#include "Eura/TextDocumentPositionParams.hpp"

namespace Eura
{
    struct [[nodiscard]] PrepareRenameParams final : TextDocumentPositionParams,
    WorkDoneProgressParams{};

    auto from_json(const nlohmann::json& object, PrepareRenameParams& prepare_rename_params)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const PrepareRenameParams& prepare_rename_params) noexcept
    -> void;
}

#endif
#endif