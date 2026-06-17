// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_workspace_folder
#define lyrix_header_guard_eura_workspace_folder
#include "Eura/URI.hpp"
#include "Eura/Any.hpp"

namespace Eura
{
    struct [[nodiscard]] WorkspaceFolder final
    {
        URI uri;

        Json::String name;
    };

    auto Deserialize(const Json::Object& object, WorkspaceFolder& workspace_folder) noexcept ->
    void;

    auto Serialize(Json::Object& object, const WorkspaceFolder& workspace_folder) noexcept -> void;
}

#endif
#endif