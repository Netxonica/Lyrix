// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Initialize.hpp"
#include "Eura/Client.hpp"
#include "Eura/ErrorCodes.hpp"
#include "Eura/ResponseMessage.hpp"
#include "Eura/InitializeParams.hpp"
#include "Eura/InitializeResult.hpp"
#include "Eura/WindowShowMessage.hpp"
#include "Eura/ServerCapabilities.hpp"

namespace Eura
{
    auto Initialize(std::mutex& mutex, const RequestMessage& request_message, std::atomic<
    Initialization>& initialization) noexcept -> void
    {
        if(request_message.method == "initialize")
        {
            InitializeParams initialize_params;
            from_json(*request_message.params, initialize_params);
            InitializeResult initialize_result;
            ServerCapabilities server_capabilities;
            if(initialize_params.capabilities.general.has_value())
                if(initialize_params.capabilities.general->positionEncodings.has_value())
                    if(not initialize_params.capabilities.general->positionEncodings->empty())
                        server_capabilities.positionEncoding = (*initialize_params.capabilities.
                        general->positionEncodings)[0uz];
            initialize_result.capabilities = server_capabilities;
            ResponseMessage response_message;
            response_message.jsonrpc = "2.0";
            std::visit([&response_message](auto&& id)
            {
                response_message.id = id;
            }, request_message.id);
            nlohmann::json result;
            to_json(result, initialize_result);
            response_message.result = result;
            nlohmann::json initialize_response;
            to_json(initialize_response, response_message);
            initialization.store(Initialization::Initializing);
            Client(mutex, initialize_response.dump());
        }
        else
        {
            ResponseMessage response_message;
            response_message.jsonrpc = "2.0";
            std::visit([&response_message](auto&& id)
            {
                response_message.id = id;
            }, request_message.id);
            ResponseError response_error;
            response_error.message = "The server was still uninitialized";
            response_error.code = static_cast<std::int32_t>(ErrorCodes::
            ServerNotInitialized);
            response_message.error = response_error;
            nlohmann::json result;
            to_json(result, response_message);
            Client(mutex, result.dump());
        }
    }
}

#endif