// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CancelParams.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, CancelParams& cancel_params) noexcept -> void
    {
        const Json::Any& id = object.Retrieve("id");
        if(id.IsUinteger())
            cancel_params.id = static_cast<Json::Integer>(id.As<Json::Uinteger>());
        else if(id.IsInteger())
            cancel_params.id = id.As<Json::Integer>();
        else if(id.IsString())
            cancel_params.id = id.As<Json::String>();
        else
            std::abort();
    }

    auto Serialize(Json::Object& object, const CancelParams& cancel_params) noexcept -> void
    {
        cancel_params.id.visit([&object](auto&& id)
        {
            object.fields.emplace_back("id", id);
        });
    }
}

#endif