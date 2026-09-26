// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentOnTypeFormattingParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"textDocument\":{\"uri\":\"meow.extension\"},\"position\":{\"line\":42,\"character\":67},\"ch\":\"nya\",\"options\":{\"tabSize\":67,\"insertSpaces\":true,\"trimTrailingWhitespace\":true,\"insertFinalNewline\":true,\"trimFinalNewlines\":true,\"meow\":true}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::DocumentOnTypeFormattingParams request;
    Eura::from_json(root, request);
    if(request.textDocument.uri not_eq "meow.extension" or request.position.line not_eq 42u or
    request.position.character not_eq 67u or request.ch not_eq "nya" or request.options.tabSize
    not_eq 67u or not request.options.insertSpaces or not request.options.trimTrailingWhitespace.
    has_value() or not *request.options.trimTrailingWhitespace or not request.options.
    insertFinalNewline.has_value() or not *request.options.insertFinalNewline or not request.
    options.trimFinalNewlines.has_value() or not *request.options.trimFinalNewlines or request.
    options.optional.size() not_eq 1uz)
        return false;
    for(const auto& [key, value] : request.options.optional)
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