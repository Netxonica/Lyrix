// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TypeHierarchySubtypesParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TypeHierarchySubtypesParams&
    type_hierarchy_subtypes_params) noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(type_hierarchy_subtypes_params));
        from_json(object, static_cast<PartialResultParams&>(type_hierarchy_subtypes_params));
        type_hierarchy_subtypes_params.item = object.at("item").get<TypeHierarchyItem>();
    }

    auto to_json(nlohmann::json& object, const TypeHierarchySubtypesParams&
    type_hierarchy_subtypes_params) noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(type_hierarchy_subtypes_params))
        ;
        to_json(object, static_cast<const PartialResultParams&>(type_hierarchy_subtypes_params));
        object["item"] = type_hierarchy_subtypes_params.item;
    }
}

#endif