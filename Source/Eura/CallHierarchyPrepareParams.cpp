// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CallHierarchyPrepareParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CallHierarchyPrepareParams&
    call_hierarchy_prepare_params) noexcept -> void
    {
        from_json(object, static_cast<TextDocumentPositionParams&>(call_hierarchy_prepare_params));
        from_json(object, static_cast<WorkDoneProgressParams&>(call_hierarchy_prepare_params));
    }

    auto to_json(nlohmann::json& object, const CallHierarchyPrepareParams&
    call_hierarchy_prepare_params) noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentPositionParams&>(
        call_hierarchy_prepare_params));
        to_json(object, static_cast<const WorkDoneProgressParams&>(call_hierarchy_prepare_params));
    }
}

#endif