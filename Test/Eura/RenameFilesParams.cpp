// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/RenameFilesParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"files\":[{\"oldUri\":\"meow.extension\",\"newUri\":\"nya.extension\"}]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::RenameFilesParams request;
    Eura::from_json(root, request);
    if(request.files.size() not_eq 1uz or request.files[0uz].oldUri not_eq "meow.extension" or
    request.files[0uz].newUri not_eq "nya.extension")
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