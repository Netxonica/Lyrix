// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DiagnosticRelatedInformation.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"location\":{\"uri\":\"meow.extension\",\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}}},\"message\":\"meow nya\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::DiagnosticRelatedInformation request;
    Eura::from_json(root, request);
    if(request.location.uri not_eq "meow.extension" or request.location.range.start.line not_eq 0u
    or request.location.range.start.character not_eq 0u or request.location.range.end.line not_eq
    42u or request.location.range.end.character not_eq 67u or request.message not_eq "meow nya")
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