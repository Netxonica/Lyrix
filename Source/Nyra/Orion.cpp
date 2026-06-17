// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/Orion.hpp"
#include <memory>
#include "Nyra/File.hpp"
#include "Nyra/Error.hpp"
#include "Nyra/Directory.hpp"

namespace Nyra
{
    Orion::Orion(const std::string_view name) noexcept : m_name(name){}

    [[nodiscard]] auto Orion::Elyra() const noexcept -> std::string
    {
        return std::string(m_name) + ".orion/" + std::string(m_name) + ".elyra";
    }

    [[nodiscard]] auto Orionify(const std::string_view name) noexcept -> std::optional<Orion>
    {
        std::string base{name};
        base += ".orion/";
        if(not Directory::Exists(base))
        {
            std::make_unique<Error>(19uz, name, base)->Report();
            return std::nullopt;
        }
        else if(not File::Exists(base + std::string(name) + ".elyra"))
        {
            std::make_unique<Error>(20uz, name, base + std::string(name) + ".elyra")->Report();
            return std::nullopt;
        }
        return Orion(name);
    }
}

#endif