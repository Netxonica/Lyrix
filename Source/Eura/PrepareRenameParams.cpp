// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/PrepareRenameParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, PrepareRenameParams& prepare_rename_params)
    noexcept -> void
    {
        from_json(object, static_cast<TextDocumentPositionParams&>(prepare_rename_params));
        from_json(object, static_cast<WorkDoneProgressParams&>(prepare_rename_params));
    }

    auto to_json(nlohmann::json& object, const PrepareRenameParams& prepare_rename_params) noexcept
    -> void
    {
        to_json(object, static_cast<const TextDocumentPositionParams&>(prepare_rename_params));
        to_json(object, static_cast<const WorkDoneProgressParams&>(prepare_rename_params));
    }
}

#endif