// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InitializedParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json&, InitializedParams&) noexcept -> void{}

    auto to_json(nlohmann::json& object, const InitializedParams&) noexcept -> void
    {
        object = nlohmann::json::object();
    }
}

#endif