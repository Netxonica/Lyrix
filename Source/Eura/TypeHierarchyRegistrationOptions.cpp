// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TypeHierarchyRegistrationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TypeHierarchyRegistrationOptions&
    type_hierarchy_registration_options) noexcept -> void
    {
        from_json(object, static_cast<TextDocumentRegistrationOptions&>(
        type_hierarchy_registration_options));
        from_json(object, static_cast<TypeHierarchyOptions&>(type_hierarchy_registration_options));
        from_json(object, static_cast<StaticRegistrationOptions&>(
        type_hierarchy_registration_options));
    }

    auto to_json(nlohmann::json& object, const TypeHierarchyRegistrationOptions&
    type_hierarchy_registration_options) noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentRegistrationOptions&>(
        type_hierarchy_registration_options));
        to_json(object, static_cast<const TypeHierarchyOptions&>(
        type_hierarchy_registration_options));
        to_json(object, static_cast<const StaticRegistrationOptions&>(
        type_hierarchy_registration_options));
    }
}

#endif