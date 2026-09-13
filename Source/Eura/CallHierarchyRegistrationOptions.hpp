// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_call_hierarchy_registration_options
#define lyrix_header_guard_eura_call_hierarchy_registration_options
#include "Eura/CallHierarchyOptions.hpp"
#include "Eura/StaticRegistrationOptions.hpp"
#include "Eura/TextDocumentRegistrationOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] CallHierarchyRegistrationOptions final : TextDocumentRegistrationOptions,
    CallHierarchyOptions, StaticRegistrationOptions{};

    auto from_json(const nlohmann::json& object, CallHierarchyRegistrationOptions&
    call_hierarchy_registration_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const CallHierarchyRegistrationOptions&
    call_hierarchy_registration_options) noexcept -> void;
}

#endif
#endif