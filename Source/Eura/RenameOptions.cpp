// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/RenameOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, RenameOptions& rename_options) noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressOptions&>(rename_options));
        if(object.contains("prepareProvider"))
            rename_options.prepareProvider = object.at("prepareProvider").get<bool>();
    }

    auto to_json(nlohmann::json& object, const RenameOptions& rename_options) noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressOptions&>(rename_options));
        if(rename_options.prepareProvider.has_value())
            object["prepareProvider"] = *rename_options.prepareProvider;
    }
}

#endif