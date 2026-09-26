// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FormattingOptions.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"tabSize\":67,\"insertSpaces\":true,\"trimTrailingWhitespace\":true,\"insertFinalNewline\":true,\"trimFinalNewlines\":true,\"meow\":true}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::FormattingOptions request;
    Eura::from_json(root, request);
    if(request.tabSize not_eq 67u or not request.insertSpaces or not request.trimTrailingWhitespace
    .has_value() or not *request.trimTrailingWhitespace or not request.insertFinalNewline.has_value
    () or not *request.insertFinalNewline or not request.trimFinalNewlines.has_value() or not *
    request.trimFinalNewlines or request.optional.size() not_eq 1uz)
        return false;
    for(const auto& [key, value] : request.optional)
        if(key not_eq "meow" or not std::holds_alternative<bool>(value) or not std::get<bool>(value
        ))
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