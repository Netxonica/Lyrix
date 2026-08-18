// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/RequestMessage.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, RequestMessage& request_message) noexcept -> void
    {
        from_json(object, static_cast<Message&>(request_message));
        const nlohmann::json& id = object.at("id");
        if(id.is_number_integer())
            request_message.id = id.get<std::int32_t>();
        else
            request_message.id = id.get<std::string>();
    }

    auto to_json(nlohmann::json& object, const RequestMessage& request_message) noexcept -> void
    {
        to_json(object, static_cast<const Message&>(request_message));
        std::visit([&object](auto&& id)
        {
            object["id"] = id;
        }, request_message.id);
    }
}

#endif