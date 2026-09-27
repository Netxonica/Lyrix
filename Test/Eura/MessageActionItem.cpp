// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/MessageActionItem.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"title\":\"meow\",\"nya\":true}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::MessageActionItem request;
    Eura::from_json(root, request);
    if(request.title not_eq "meow" or request.optional.size() not_eq 1uz)
        return false;
    for(const auto& [key, value] : request.optional)
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