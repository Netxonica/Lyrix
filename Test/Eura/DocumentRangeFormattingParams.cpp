// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentRangeFormattingParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"workDoneToken\":\"meow\",\"textDocument\":{\"uri\":\"meow.extension\"},\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"options\":{\"tabSize\":67,\"insertSpaces\":true,\"trimTrailingWhitespace\":true,\"insertFinalNewline\":true,\"trimFinalNewlines\":true,\"meow\":true}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::DocumentRangeFormattingParams request;
    Eura::from_json(root, request);
    if(not request.workDoneToken.has_value() or not std::holds_alternative<std::string>(*request.
    workDoneToken) or std::get<std::string>(*request.workDoneToken) not_eq "meow" or request.
    textDocument.uri not_eq "meow.extension" or request.range.start.line not_eq 0u or request.range
    .start.character not_eq 0u or request.range.end.line not_eq 42u or request.range.end.character
    not_eq 67u or request.options.tabSize not_eq 67u or not request.options.insertSpaces or not
    request.options.trimTrailingWhitespace.has_value() or not *request.options.
    trimTrailingWhitespace or not request.options.insertFinalNewline.has_value() or not *request.
    options.insertFinalNewline or not request.options.trimFinalNewlines.has_value() or not *request
    .options.trimFinalNewlines or request.options.optional.size() not_eq 1uz)
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