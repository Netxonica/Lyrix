// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/WorkspaceSymbol.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"name\":\"meow\",\"kind\":24,\"tags\":[1],\"containerName\":\"nya\",\"location\":{\"uri\":\"meow.extension\"},\"data\":{\"jsonrpc\":\"2.0\"}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::WorkspaceSymbol request;
    Eura::from_json(root, request);
    if(request.name not_eq "meow" or request.kind not_eq Eura::SymbolKind::Event or not request.
    tags.has_value() or request.tags->size() not_eq 1uz or (*request.tags)[0uz] not_eq Eura::
    SymbolTag::Deprecated or not request.containerName.has_value() or *request.containerName not_eq
    "nya" or not std::holds_alternative<Eura::LocationUriOnly>(request.location) or std::get<Eura::
    LocationUriOnly>(request.location).uri not_eq "meow.extension" or not request.data.has_value())
        return false;
    Eura::Message message;
    Eura::from_json(*request.data, message);
    if(message.jsonrpc not_eq "2.0")
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