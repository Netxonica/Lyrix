// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Json.hpp"
#include "Eura/AnnotatedTextEdit.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    Eura::Json::Strings strings;
    const std::string content = "{\"range\":{\"start\":{\"line\":42,\"character\":7},\"end\":{\"line\":67,\"character\":6}},\"newText\":\"meow\",\"annotationId\":\"lmao\"}";
    Eura::Json::Root root = Eura::Json::Deserialize(content, strings);
    Eura::AnnotatedTextEdit request;
    Eura::Deserialize(root, request);
    if(request.range.start.line not_eq 42u or request.range.start.character not_eq 7u or request.
    range.end.line not_eq 67u or request.range.end.character not_eq 6u or request.newText not_eq
    "meow" or request.annotationId not_eq "lmao")
        return false;
    Eura::Json::Root response;
    Eura::Serialize(response, request);
    return Eura::Json::Serialize(response) == content;
}

int main()
{
    return not lyrix_test();
}

#endif