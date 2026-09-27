// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/LogMessageParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"type\":4,\"message\":\"nya\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::LogMessageParams request;
    Eura::from_json(root, request);
    if(request.type not_eq Eura::MessageType::Log or request.message not_eq "nya")
        return false;
    nlohmann::json response;
    Eura::to_json(response, request);
    return response == root;
}

int main()
{
    return not lyrix_test();
}

#endif