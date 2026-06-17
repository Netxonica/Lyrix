// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ResponseError.hpp"

namespace Eura
{
    auto Deserialize(Json::Object& object, ResponseError& response_error) noexcept -> void
    {
        const Json::Any& code = object.Retrieve("code");
        response_error.code = code.IsUinteger() ? static_cast<Json::Integer>(code.As<Json::Uinteger
        >()) : code.As<Json::Integer>();
        response_error.message = object.Retrieve("message").As<Json::String>();
        if(object.Contains("data"))
            response_error.data = std::move(object.Retrieve("data"));
    }

    auto Serialize(Json::Object& object, ResponseError& response_error) noexcept -> void
    {
        object.fields.emplace_back("code", response_error.code);
        object.fields.emplace_back("message", response_error.message);
        if(response_error.data.has_value())
            response_error.data->visit([&object](auto&& data)
            {
                object.fields.emplace_back("data", std::move(data));
            });
    }
}

#endif