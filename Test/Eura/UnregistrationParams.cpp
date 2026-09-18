// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/UnregistrationParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"unregistrations\":[{\"id\":\"meow\",\"method\":\"nya\"}]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::UnregistrationParams request;
    Eura::from_json(root, request);
    if(request.unregistrations.size() not_eq 1uz or request.unregistrations[0uz].id not_eq "meow"
    or request.unregistrations[0uz].method not_eq "nya")
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