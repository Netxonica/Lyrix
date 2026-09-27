// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ShowMessageRequestParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"type\":3,\"message\":\"meow\",\"actions\":[{\"title\":\"meow\",\"nya\":true}]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::ShowMessageRequestParams request;
    Eura::from_json(root, request);
    if(request.type not_eq Eura::MessageType::Info or request.message not_eq "meow" or not request.
    actions.has_value() or request.actions->size() not_eq 1uz or (*request.actions)[0uz].title
    not_eq "meow" or (*request.actions)[0uz].optional.size() not_eq 1uz)
        return false;
    for(const auto& [key, value] : (*request.actions)[0uz].optional)
        if(key not_eq "nya" or not std::holds_alternative<bool>(value) or not std::get<bool>(value)
        )
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