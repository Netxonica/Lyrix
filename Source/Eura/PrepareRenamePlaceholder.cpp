// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/PrepareRenamePlaceholder.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, PrepareRenamePlaceholder&
    prepare_rename_placeholder) noexcept -> void
    {
        prepare_rename_placeholder.range = object.at("range").get<Range>();
        prepare_rename_placeholder.placeholder = object.at("placeholder").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const PrepareRenamePlaceholder& prepare_rename_placeholder
    ) noexcept -> void
    {
        object["range"] = prepare_rename_placeholder.range;
        object["placeholder"] = prepare_rename_placeholder.placeholder;
    }
}

#endif