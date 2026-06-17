// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/RequestMessage.hpp"

namespace Eura
{
    auto Deserialize(Json::Object& object, RequestMessage& request_message) noexcept -> void
    {
        Deserialize(object, static_cast<Message&>(request_message));
        object.Retrieve("id").visit([&request_message](auto&& id)
        {
            using T = std::decay_t<decltype(id)>;
            if constexpr(std::is_same_v<T, Json::String> or std::is_same_v<T, Json::Integer>)
                request_message.id = id;
            else if constexpr(std::is_same_v<T, Json::Uinteger>)
                request_message.id = static_cast<Json::Integer>(id);
            else
                std::abort();
        });
        const Json::Any& method = object.Retrieve("method");
        if(not method.IsString())
            std::abort();
        request_message.method = method.As<Json::String>();
        if(object.Contains("params"))
        {
            Json::Any& params = object.Retrieve("params");
            if(params.IsObject())
                request_message.params = std::move(params.As<Json::Object>());
            else if(params.IsArray())
                request_message.params = std::move(params.As<Json::Array>());
            else
                std::abort();
        }
    }

    auto Serialize(Json::Object& object, RequestMessage& request_message) noexcept -> void
    {
        Serialize(object, static_cast<const Message&>(request_message));
        request_message.id.visit([&object](auto&& id)
        {
            object.fields.emplace_back("id", id);
        });
        object.fields.emplace_back("method", request_message.method);
        if(request_message.params.has_value())
            request_message.params->visit([&object](auto&& params)
            {
                object.fields.emplace_back("params", std::move(params));
            });
    }
}

#endif