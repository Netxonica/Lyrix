// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_call_hierarchy_outgoing_calls_params
#define lyrix_header_guard_eura_call_hierarchy_outgoing_calls_params
#include "Eura/CallHierarchyItem.hpp"
#include "Eura/PartialResultParams.hpp"
#include "Eura/WorkDoneProgressParams.hpp"

namespace Eura
{
    struct [[nodiscard]] CallHierarchyOutgoingCallsParams final : WorkDoneProgressParams,
    PartialResultParams
    {
        CallHierarchyItem item;
    };

    auto from_json(const nlohmann::json& object, CallHierarchyOutgoingCallsParams&
    call_hierarchy_outgoing_calls_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const CallHierarchyOutgoingCallsParams&
    call_hierarchy_outgoing_calls_params) noexcept -> void;
}

#endif
#endif