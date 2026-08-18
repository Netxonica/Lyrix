// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CancelParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CancelParams& cancel_params) noexcept -> void
    {
        const nlohmann::json& id = object.at("id");
        if(id.is_number_integer())
            cancel_params.id = id.get<std::int32_t>();
        else
            cancel_params.id = id.get<std::string>();
    }

    auto to_json(nlohmann::json& object, const CancelParams& cancel_params) noexcept -> void
    {
        std::visit([&object](auto&& id)
        {
            object["id"] = id;
        }, cancel_params.id);
    }
}

#endif