// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TypeHierarchyPrepareParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TypeHierarchyPrepareParams&
    type_hierarchy_prepare_params) noexcept -> void
    {
        from_json(object, static_cast<TextDocumentPositionParams&>(type_hierarchy_prepare_params));
        from_json(object, static_cast<WorkDoneProgressParams&>(type_hierarchy_prepare_params));
    }

    auto to_json(nlohmann::json& object, const TypeHierarchyPrepareParams&
    type_hierarchy_prepare_params) noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentPositionParams&>(
        type_hierarchy_prepare_params));
        to_json(object, static_cast<const WorkDoneProgressParams&>(type_hierarchy_prepare_params));
    }
}

#endif