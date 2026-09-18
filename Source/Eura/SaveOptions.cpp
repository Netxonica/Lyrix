// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SaveOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SaveOptions& save_options) noexcept -> void
    {
        if(object.contains("includeText"))
            save_options.includeText = object.at("includeText").get<bool>();
    }

    auto to_json(nlohmann::json& object, const SaveOptions& save_options) noexcept -> void
    {
        if(save_options.includeText.has_value())
            object["includeText"] = *save_options.includeText;
    }
}

#endif