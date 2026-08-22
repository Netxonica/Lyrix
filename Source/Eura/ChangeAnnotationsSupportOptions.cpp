// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ChangeAnnotationsSupportOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ChangeAnnotationsSupportOptions&
    change_annotations_support_options) noexcept -> void
    {
        if(object.contains("groupsOnLabel"))
            change_annotations_support_options.groupsOnLabel = object.at("groupsOnLabel").get<bool>
            ();
    }

    auto to_json(nlohmann::json& object, const ChangeAnnotationsSupportOptions&
    change_annotations_support_options) noexcept -> void
    {
        if(change_annotations_support_options.groupsOnLabel.has_value())
            object["groupsOnLabel"] = *change_annotations_support_options.groupsOnLabel;
    }
}

#endif