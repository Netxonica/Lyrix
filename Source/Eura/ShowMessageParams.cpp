// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ShowMessageParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ShowMessageParams& show_message_params) noexcept
    -> void
    {
        show_message_params.type = object.at("type").get<MessageType>();
        show_message_params.message = object.at("message").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const ShowMessageParams& show_message_params) noexcept ->
    void
    {
        object["type"] = show_message_params.type;
        object["message"] = show_message_params.message;
    }
}

#endif