// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ResponseMessage.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"jsonrpc\":\"2.0\",\"id\":null,\"result\":{\"jsonrpc\":\"2.0\"},\"error\":{\"code\":67,\"message\":\"nya\",\"data\":{\"jsonrpc\":\"2.0\"}}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::ResponseMessage request;
    Eura::from_json(root, request);
    if(request.jsonrpc not_eq "2.0" or not std::holds_alternative<std::nullptr_t>(request.id) or
    not request.result.has_value() or not request.error.has_value() or request.error->code not_eq
    67 or request.error->message not_eq "nya" or not request.error->data.has_value())
        return false;
    Eura::Message message;
    Eura::from_json(*request.result, message);
    if(message.jsonrpc not_eq "2.0")
        return false;
    Eura::Message error_message;
    Eura::from_json(*request.error->data, error_message);
    if(error_message.jsonrpc not_eq "2.0")
        return false;
    nlohmann::json response;
    Eura::to_json(response, request);
    return response.dump() == root.dump();
}

int main()
{
    return not lyrix_test();
}

#endif