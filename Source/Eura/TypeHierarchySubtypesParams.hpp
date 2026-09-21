// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_type_hierarchy_subtypes_params
#define lyrix_header_guard_eura_type_hierarchy_subtypes_params
#include "Eura/TypeHierarchyItem.hpp"
#include "Eura/PartialResultParams.hpp"
#include "Eura/WorkDoneProgressParams.hpp"

namespace Eura
{
    struct [[nodiscard]] TypeHierarchySubtypesParams final : WorkDoneProgressParams,
    PartialResultParams
    {
        TypeHierarchyItem item;
    };

    auto from_json(const nlohmann::json& object, TypeHierarchySubtypesParams&
    type_hierarchy_subtypes_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const TypeHierarchySubtypesParams&
    type_hierarchy_subtypes_params) noexcept -> void;
}

#endif
#endif