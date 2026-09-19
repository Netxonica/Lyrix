// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_call_hierarchy_outgoing_call
#define lyrix_header_guard_eura_call_hierarchy_outgoing_call
#include "Eura/CallHierarchyItem.hpp"

namespace Eura
{
    struct [[nodiscard]] CallHierarchyOutgoingCall final
    {
        CallHierarchyItem to;

        std::vector<Range> fromRanges;
    };

    auto from_json(const nlohmann::json& object, CallHierarchyOutgoingCall&
    call_hierarchy_outgoing_call) noexcept -> void;

    auto to_json(nlohmann::json& object, const CallHierarchyOutgoingCall&
    call_hierarchy_outgoing_call) noexcept -> void;
}

#endif
#endif