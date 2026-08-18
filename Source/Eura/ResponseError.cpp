// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ResponseError.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ResponseError& response_error) noexcept -> void
    {
        response_error.code = object.at("code").get<std::int32_t>();
        response_error.message = object.at("message").get<std::string>();
        if(object.contains("data"))
            response_error.data = object.at("data");
    }

    auto to_json(nlohmann::json& object, const ResponseError& response_error) noexcept -> void
    {
        object["code"] = response_error.code;
        object["message"] = response_error.message;
        if(response_error.data.has_value())
            object["data"] = *response_error.data;
    }
}

#endif