// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkDoneProgressReport.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"kind\":\"report\",\"cancellable\":true,\"message\":\"meow nya\",\"percentage\":67}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::WorkDoneProgressReport request;
    Eura::from_json(root, request);
    if(request.kind not_eq "report" or not request.cancellable.has_value() or not *request.
    cancellable or not request.message.has_value() or *request.message not_eq "meow nya" or not
    request.percentage.has_value() or *request.percentage not_eq 67u)
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