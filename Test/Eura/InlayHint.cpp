// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/InlayHint.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"position\":{\"line\":42,\"character\":67},\"label\":\"nya\",\"kind\":2,\"textEdits\":[{\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"newText\":\"meow nya\"}],\"tooltip\":\"nya\",\"paddingLeft\":true,\"paddingRight\":true,\"data\":{\"jsonrpc\":\"2.0\"}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::InlayHint request;
    Eura::from_json(root, request);
    if(request.position.line not_eq 42u or request.position.character not_eq 67u or not std::
    holds_alternative<std::string>(request.label) or std::get<std::string>(request.label) not_eq
    "nya" or not request.kind.has_value() or *request.kind not_eq Eura::InlayHintKind::Parameter or
    not request.textEdits.has_value() or request.textEdits->size() not_eq 1uz or (*request.
    textEdits)[0uz].range.start.line not_eq 0u or (*request.textEdits)[0uz].range.start.character
    not_eq 0u or (*request.textEdits)[0uz].range.end.line not_eq 42u or (*request.textEdits)[0uz].
    range.end.character not_eq 67u or (*request.textEdits)[0uz].newText not_eq "meow nya" or not
    request.tooltip.has_value() or not std::holds_alternative<std::string>(*request.tooltip) or std
    ::get<std::string>(*request.tooltip) not_eq "nya" or not request.paddingLeft.has_value() or not
    *request.paddingLeft or not request.paddingRight.has_value() or not *request.paddingRight or
    not request.data.has_value())
        return false;
    Eura::Message message;
    Eura::from_json(*request.data, message);
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