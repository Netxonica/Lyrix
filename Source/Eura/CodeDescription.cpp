// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CodeDescription.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CodeDescription& code_description) noexcept ->
    void
    {
        code_description.href = object.at("href").get<URI>();
    }

    auto to_json(nlohmann::json& object, const CodeDescription& code_description) noexcept -> void
    {
        object["href"] = code_description.href;
    }
}

#endif