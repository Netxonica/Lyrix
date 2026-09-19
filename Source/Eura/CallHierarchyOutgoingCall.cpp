// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CallHierarchyOutgoingCall.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CallHierarchyOutgoingCall&
    call_hierarchy_outgoing_call) noexcept -> void
    {
        call_hierarchy_outgoing_call.to = object.at("to").get<CallHierarchyItem>();
        const nlohmann::json& fromRanges = object.at("fromRanges");
        for(const nlohmann::json& fromRange : fromRanges)
            call_hierarchy_outgoing_call.fromRanges.emplace_back(fromRange.get<Range>());
    }

    auto to_json(nlohmann::json& object, const CallHierarchyOutgoingCall&
    call_hierarchy_outgoing_call) noexcept -> void
    {
        object["to"] = call_hierarchy_outgoing_call.to;
        nlohmann::json fromRanges = nlohmann::json::array();
        for(const Range& fromRange : call_hierarchy_outgoing_call.fromRanges)
            fromRanges.emplace_back(fromRange);
        object["fromRanges"] = fromRanges;
    }
}

#endif