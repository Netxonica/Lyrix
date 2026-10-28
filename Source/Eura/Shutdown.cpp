// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Shutdown.hpp"
#include "Eura/ResponseMessage.hpp"

namespace Eura
{
    [[nodiscard]] auto Shutdown(const std::variant<std::int32_t, std::string>& id, std::atomic_bool
    & ready_to_close) noexcept -> std::string
    {
        ResponseMessage response_message;
        response_message.jsonrpc = "2.0";
        std::visit([&response_message](auto&& id)
        {
            response_message.id = id;
        }, id);
        nlohmann::json response;
        to_json(response, response_message);        
        ready_to_close.store(true);
        return response.dump();
    }
}

#endif