// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ParameterInformation.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"label\":[42,67],\"documentation\":\"meow nya\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::ParameterInformation request;
    Eura::from_json(root, request);
    if(not std::holds_alternative<std::array<std::uint32_t, 2uz>>(request.label))
        return false;
    const std::array<std::uint32_t, 2uz> label = std::get<std::array<std::uint32_t, 2uz>>(request.
    label);
    if(label[0uz] not_eq 42u or label[1uz] not_eq 67u or not request.documentation.has_value() or
    not std::holds_alternative<std::string>(*request.documentation) or std::get<std::string>(*
    request.documentation) not_eq "meow nya")
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