// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ResponseMessage.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ResponseMessage& response_message) noexcept ->
    void
    {
        from_json(object, static_cast<Message&>(response_message));
        const nlohmann::json& id = object.at("id");
        if(id.is_number_integer())
            response_message.id = id.get<std::int32_t>();
        else if(id.is_string())
            response_message.id = id.get<std::string>();
        else
            response_message.id = nullptr;
        if(object.contains("result"))
            response_message.result = object.at("result");
    }

    auto to_json(nlohmann::json& object, const ResponseMessage& response_message) noexcept -> void
    {
        to_json(object, static_cast<const Message&>(response_message));
        std::visit([&object](auto&& id)
        {
            object["id"] = id;
        }, response_message.id);
        if(response_message.result.has_value())
            object["result"] = *response_message.result;
    }
}

#endif