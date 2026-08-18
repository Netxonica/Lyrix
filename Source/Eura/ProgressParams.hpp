// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_progress_params
#define lyrix_header_guard_eura_progress_params
#include "Eura/Json.hpp"
#include "Eura/ProgressToken.hpp"

namespace Eura
{
    template<class T> struct [[nodiscard]] ProgressParams final
    {
        ProgressToken token;

        T value;
    };

    template<class T> auto from_json(const nlohmann::json& object, ProgressParams<T>&
    progress_params) noexcept -> void
    {
        const nlohmann::json& token = object.at("token");
        if(token.is_number_integer())
            progress_params.token = token.get<std::int32_t>();
        else
            progress_params.token = token.get<std::string>();
        object.at("value").get_to(progress_params.value);
    }

    template<class T> auto to_json(nlohmann::json& object, const ProgressParams<T>& progress_params
    ) noexcept -> void
    {
        std::visit([&object](auto&& token)
        {
            object["token"] = token;
        }, progress_params.token);
        object["value"] = progress_params.value;
    }
}

#endif
#endif