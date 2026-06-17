// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Object.hpp"
#include "Eura/Any.hpp"

namespace Eura::Json
{
    [[nodiscard]] auto Object::Contains(const std::string_view name) const noexcept -> bool
    {
        for(const std::pair<String, Any>& field : fields)
            if(field.first == name)
                return true;
        return false;
    }

    [[nodiscard]] auto Object::Retrieve(const std::string_view name) noexcept -> Any&
    {
        for(std::pair<String, Any>& field : fields)
            if(field.first == name)
                return field.second;
        std::abort();
    }

    [[nodiscard]] auto Object::Retrieve(const std::string_view name) const noexcept -> const Any&
    {
        for(const std::pair<String, Any>& field : fields)
            if(field.first == name)
                return field.second;
        std::abort();
    }

    [[nodiscard]] auto Object::NestedObject(const std::string_view name) noexcept -> Object&
    {
        fields.emplace_back(name, Object{});
        return fields.back().second.As<Object>();
    }

    [[nodiscard]] auto Object::NestedArray(const std::string_view name) noexcept -> Array&
    {
        fields.emplace_back(name, Array{});
        return fields.back().second.As<Array>();
    }
}

#endif