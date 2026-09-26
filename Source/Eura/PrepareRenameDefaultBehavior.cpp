// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/PrepareRenameDefaultBehavior.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, PrepareRenameDefaultBehavior&
    prepare_rename_default_behavior) noexcept -> void
    {
        prepare_rename_default_behavior.defaultBehavior = object.at("defaultBehavior").get<bool>();
    }

    auto to_json(nlohmann::json& object, const PrepareRenameDefaultBehavior&
    prepare_rename_default_behavior) noexcept -> void
    {
        object["defaultBehavior"] = prepare_rename_default_behavior.defaultBehavior;
    }
}

#endif