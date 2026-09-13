// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentOnTypeFormattingOptions.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"firstTriggerCharacter\":\"meow\",\"moreTriggerCharacter\":[\"nya\"]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::DocumentOnTypeFormattingOptions request;
    Eura::from_json(root, request);
    if(request.firstTriggerCharacter not_eq "meow" or not request.moreTriggerCharacter.has_value()
    or request.moreTriggerCharacter->size() not_eq 1uz or (*request.moreTriggerCharacter)[0uz]
    not_eq "nya")
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