// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_call_hierarchy_prepare_params
#define lyrix_header_guard_eura_call_hierarchy_prepare_params
#include "Eura/WorkDoneProgressParams.hpp"
#include "Eura/TextDocumentPositionParams.hpp"

namespace Eura
{
    struct [[nodiscard]] CallHierarchyPrepareParams final : TextDocumentPositionParams,
    WorkDoneProgressParams{};

    auto from_json(const nlohmann::json& object, CallHierarchyPrepareParams&
    call_hierarchy_prepare_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const CallHierarchyPrepareParams&
    call_hierarchy_prepare_params) noexcept -> void;
}

#endif
#endif