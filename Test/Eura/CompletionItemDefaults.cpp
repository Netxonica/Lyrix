// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/CompletionItemDefaults.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"commitCharacters\":[\"meow\"],\"editRange\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"insertTextFormat\":2,\"insertTextMode\":2,\"data\":{\"jsonrpc\":\"2.0\"}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::CompletionItemDefaults request;
    Eura::from_json(root, request);
    if(not request.commitCharacters.has_value() or request.commitCharacters->size() not_eq 1uz or (
    *request.commitCharacters)[0uz] not_eq "meow" or not request.editRange.has_value() or not std::
    holds_alternative<Eura::Range>(*request.editRange))
        return false;
    const Eura::Range& range = std::get<Eura::Range>(*request.editRange);
    if(range.start.line not_eq 0u or range.start.character not_eq 0u or range.end.line not_eq 42u
    or range.end.character not_eq 67u or not request.insertTextFormat.has_value() or *request.
    insertTextFormat not_eq Eura::InsertTextFormat::Snippet or not request.insertTextMode.has_value
    () or *request.insertTextMode not_eq Eura::InsertTextMode::AdjustIndentation or not request.
    data.has_value())
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