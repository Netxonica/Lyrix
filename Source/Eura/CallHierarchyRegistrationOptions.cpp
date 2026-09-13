// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CallHierarchyRegistrationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CallHierarchyRegistrationOptions&
    call_hierarchy_registration_options) noexcept -> void
    {
        from_json(object, static_cast<TextDocumentRegistrationOptions&>(
        call_hierarchy_registration_options));
        from_json(object, static_cast<CallHierarchyOptions&>(call_hierarchy_registration_options));
        from_json(object, static_cast<StaticRegistrationOptions&>(
        call_hierarchy_registration_options));
    }

    auto to_json(nlohmann::json& object, const CallHierarchyRegistrationOptions&
    call_hierarchy_registration_options) noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentRegistrationOptions&>(
        call_hierarchy_registration_options));
        to_json(object, static_cast<const CallHierarchyOptions&>(
        call_hierarchy_registration_options));
        to_json(object, static_cast<const StaticRegistrationOptions&>(
        call_hierarchy_registration_options));
    }
}

#endif