// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CallHierarchyIncomingCall.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CallHierarchyIncomingCall&
    call_hierarchy_incoming_call) noexcept -> void
    {
        call_hierarchy_incoming_call.from = object.at("from").get<CallHierarchyItem>();
        const nlohmann::json& fromRanges = object.at("fromRanges");
        for(const nlohmann::json& fromRange : fromRanges)
            call_hierarchy_incoming_call.fromRanges.emplace_back(fromRange.get<Range>());
    }

    auto to_json(nlohmann::json& object, const CallHierarchyIncomingCall&
    call_hierarchy_incoming_call) noexcept -> void
    {
        object["from"] = call_hierarchy_incoming_call.from;
        nlohmann::json fromRanges = nlohmann::json::array();
        for(const Range& fromRange : call_hierarchy_incoming_call.fromRanges)
            fromRanges.emplace_back(fromRange);
        object["fromRanges"] = fromRanges;
    }
}

#endif