// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ResponseMessage.hpp"

namespace Eura
{
    auto Deserialize(Json::Object& object, ResponseMessage& response_message) noexcept -> void
    {
        Deserialize(object, static_cast<Message&>(response_message));
        object.Retrieve("id").visit([&response_message](auto&& id)
        {
            using T = std::decay_t<decltype(id)>;
            if constexpr(std::is_same_v<T, Json::String> or std::is_same_v<T, Json::Integer> or std
            ::is_same_v<T, Json::Null>)
                response_message.id = id;
            else if constexpr(std::is_same_v<T, Json::Uinteger>)
                response_message.id = static_cast<Json::Integer>(id);
            else
                std::abort();
        });
        if(object.Contains("result"))
        {
            if(object.Contains("error"))
                std::abort();
            response_message.result = std::move(object.Retrieve("result"));
        }
        else if(object.Contains("error"))
        {
            ResponseError error;
            Deserialize(object.Retrieve("error").As<Json::Object>(), error);
            response_message.error = std::move(error);
        }
    }

    auto Serialize(Json::Object& object, ResponseMessage& response_message) noexcept -> void
    {
        Serialize(object, static_cast<const Message&>(response_message));
        response_message.id.visit([&object](auto&& id)
        {
            object.fields.emplace_back("id", id);
        });
        if(response_message.result.has_value())
        {
            if(response_message.error.has_value())
                std::abort();
            object.fields.emplace_back("result", std::move(*response_message.result));
        }
        else if(response_message.error.has_value())
            Serialize(object.NestedObject("error"), *response_message.error);
    }
}

#endif