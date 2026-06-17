// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_nyra_orion
#define lyrix_header_guard_nyra_orion
#include <string>
#include <optional>
#include <string_view>

namespace Nyra
{
    class [[nodiscard]] Orion final
    {
        std::string_view m_name;
    public:
        compl Orion() noexcept = default;

        Orion() noexcept = delete;
        
        Orion(const Orion&) noexcept = delete;

        Orion(Orion&& orion) noexcept = default;

        auto operator=(const Orion&) noexcept -> Orion& = delete;

        auto operator=(Orion&&) noexcept -> Orion& = delete;

        [[nodiscard]] auto operator==(const Orion&) const noexcept -> bool = delete;

        [[nodiscard]] auto operator<=>(const Orion&) const noexcept = delete;

        explicit Orion(const std::string_view name) noexcept;

        [[nodiscard]] auto Elyra() const noexcept -> std::string;
    };

    [[nodiscard]] auto Orionify(const std::string_view name) noexcept -> std::optional<Orion>;
}

#endif
#endif