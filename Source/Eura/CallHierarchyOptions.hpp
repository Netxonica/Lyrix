// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_call_hierarchy_options
#define lyrix_header_guard_eura_call_hierarchy_options
#include "Eura/WorkDoneProgressOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] CallHierarchyOptions : WorkDoneProgressOptions{};

    auto from_json(const nlohmann::json& object, CallHierarchyOptions& call_hierarchy_options)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const CallHierarchyOptions& call_hierarchy_options)
    noexcept -> void;
}

#endif
#endif