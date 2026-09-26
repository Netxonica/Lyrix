// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ColorPresentation.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"label\":\"meow\",\"textEdit\":{\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"newText\":\"meow nya\"}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::ColorPresentation request;
    Eura::from_json(root, request);
    if(request.label not_eq "meow" or not request.textEdit.has_value() or request.textEdit->range.
    start.line not_eq 0u or request.textEdit->range.start.character not_eq 0u or request.textEdit->
    range.end.line not_eq 42u or request.textEdit->range.end.character not_eq 67u or request.
    textEdit->newText not_eq "meow nya" or request.additionalTextEdits.has_value())
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