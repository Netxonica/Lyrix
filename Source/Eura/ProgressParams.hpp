// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_progress_params
#define lyrix_header_guard_eura_progress_params
#include "Eura/Any.hpp"
#include "Eura/ProgressToken.hpp"

namespace Eura
{
    template<class T> requires std::is_default_constructible_v<T> struct [[nodiscard]]
    ProgressParams final
    {
        ProgressToken token;

        T value;
    };

    template<class T> auto Deserialize(const Json::Object& object, ProgressParams<T>&
    progress_params) noexcept -> void
    {
        const Json::Any& token = object.Retrieve("token");
        if(token.IsUinteger())
            progress_params.token = static_cast<Json::Integer>(token.As<Json::Uinteger>());
        else if(token.IsInteger())
            progress_params.token = token.As<Json::Integer>();
        else if(token.IsString())
            progress_params.token = token.As<Json::String>();
        else
            std::abort();
        Deserialize(object.Retrieve("value").As<Json::Object>(), progress_params.value);
    }

    template<class T> auto Serialize(Json::Object& object, const ProgressParams<T>& progress_params
    ) noexcept -> void
    {
        progress_params.token.visit([&object](auto&& token)
        {
            object.fields.emplace_back("token", token);
        });
        object.fields.emplace_back(object.NestedObject("value"), progress_params.value);
    }
}

#endif
#endif