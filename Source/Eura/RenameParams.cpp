// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/RenameParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, RenameParams& rename_params) noexcept -> void
    {
        from_json(object, static_cast<TextDocumentPositionParams&>(rename_params));
        from_json(object, static_cast<WorkDoneProgressParams&>(rename_params));
        rename_params.newName = object.at("newName").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const RenameParams& rename_params) noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentPositionParams&>(rename_params));
        to_json(object, static_cast<const WorkDoneProgressParams&>(rename_params));
        object["newName"] = rename_params.newName;
    }
}

#endif