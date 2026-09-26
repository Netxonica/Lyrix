// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/LinkedEditingRanges.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"ranges\":[{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}}],\"wordPattern\":\"nya\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::LinkedEditingRanges request;
    Eura::from_json(root, request);
    if(request.ranges.size() not_eq 1uz or request.ranges[0uz].start.line not_eq 0u or request.
    ranges[0uz].start.character not_eq 0u or request.ranges[0uz].end.line not_eq 42u or request.
    ranges[0uz].end.character not_eq 67u or not request.wordPattern.has_value() or *request.
    wordPattern not_eq "nya")
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