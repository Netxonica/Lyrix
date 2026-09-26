// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_workspace_symbol_params
#define lyrix_header_guard_eura_workspace_symbol_params
#include "Eura/PartialResultParams.hpp"
#include "Eura/WorkDoneProgressParams.hpp"

namespace Eura
{
    struct [[nodiscard]] WorkspaceSymbolParams final : WorkDoneProgressParams, PartialResultParams
    {
        std::string query;
    };

    auto from_json(const nlohmann::json& object, WorkspaceSymbolParams& workspace_symbol_params)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const WorkspaceSymbolParams& workspace_symbol_params)
    noexcept -> void;
}

#endif
#endif