// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CodeDescription.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, CodeDescription& code_description) noexcept ->
    void
    {
        code_description.href = object.Retrieve("href").As<URI>();
    }

    auto Serialize(Json::Object& object, const CodeDescription& code_description) noexcept -> void
    {
        object.fields.emplace_back("href", code_description.href);
    }
}

#endif