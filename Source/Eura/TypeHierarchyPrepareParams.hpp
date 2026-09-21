// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_type_hierarchy_prepare_params
#define lyrix_header_guard_eura_type_hierarchy_prepare_params
#include "Eura/WorkDoneProgressParams.hpp"
#include "Eura/TextDocumentPositionParams.hpp"

namespace Eura
{
    struct [[nodiscard]] TypeHierarchyPrepareParams final : TextDocumentPositionParams,
    WorkDoneProgressParams{};

    auto from_json(const nlohmann::json& object, TypeHierarchyPrepareParams&
    type_hierarchy_prepare_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const TypeHierarchyPrepareParams&
    type_hierarchy_prepare_params) noexcept -> void;
}

#endif
#endif