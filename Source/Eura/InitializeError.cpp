// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InitializeError.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InitializeError& initialize_error) noexcept ->
    void
    {
        initialize_error.retry = object.at("retry").get<bool>();
    }

    auto to_json(nlohmann::json& object, const InitializeError& initialize_error) noexcept -> void
    {
        object["retry"] = initialize_error.retry;
    }
}

#endif