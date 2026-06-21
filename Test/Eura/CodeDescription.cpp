// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Json.hpp"
#include "Eura/CodeDescription.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    Eura::Json::Strings strings;
    const std::string content = "{\"href\":\"meow\"}";
    Eura::Json::Root root = Eura::Json::Deserialize(content, strings);
    Eura::CodeDescription request;
    Eura::Deserialize(root, request);
    if(request.href not_eq "meow")
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