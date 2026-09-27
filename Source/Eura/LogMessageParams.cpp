// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/LogMessageParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, LogMessageParams& log_message_params) noexcept ->
    void
    {
        log_message_params.type = object.at("type").get<MessageType>();
        log_message_params.message = object.at("message").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const LogMessageParams& log_message_params) noexcept ->
    void
    {
        object["type"] = log_message_params.type;
        object["message"] = log_message_params.message;
    }
}

#endif