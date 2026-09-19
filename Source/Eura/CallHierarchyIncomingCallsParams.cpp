// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CallHierarchyIncomingCallsParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CallHierarchyIncomingCallsParams&
    call_hierarchy_incoming_calls_params) noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(call_hierarchy_incoming_calls_params
        ));
        from_json(object, static_cast<PartialResultParams&>(call_hierarchy_incoming_calls_params));
        call_hierarchy_incoming_calls_params.item = object.at("item").get<CallHierarchyItem>();
    }

    auto to_json(nlohmann::json& object, const CallHierarchyIncomingCallsParams&
    call_hierarchy_incoming_calls_params) noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(
        call_hierarchy_incoming_calls_params));
        to_json(object, static_cast<const PartialResultParams&>(
        call_hierarchy_incoming_calls_params));
        object["item"] = call_hierarchy_incoming_calls_params.item;
    }
}

#endif