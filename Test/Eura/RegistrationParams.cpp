// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/RegistrationParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"registrations\":[{\"id\":\"meow\",\"method\":\"nya\",\"registerOptions\":{\"jsonrpc\":\"2.0\"}}]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::RegistrationParams request;
    Eura::from_json(root, request);
    if(request.registrations.size() not_eq 1uz or request.registrations[0uz].id not_eq "meow" or
    request.registrations[0uz].method not_eq "nya" or not request.registrations[0uz].
    registerOptions.has_value())
        return false;
    Eura::Message message;
    Eura::from_json(*request.registrations[0uz].registerOptions, message);
    if(message.jsonrpc not_eq "2.0")
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