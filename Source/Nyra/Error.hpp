// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_nyra_error
#define lyrix_header_guard_nyra_error
#include <string_view>
#include "Lumina/Error.hpp"

namespace Nyra
{
    class [[nodiscard]] Error final : public Lumina::Error
    {
        const std::string_view m_command, m_base;
    public:
        constexpr compl Error() noexcept = default;

        explicit consteval Error() noexcept = delete;

        explicit consteval Error(const Error&) noexcept = delete;

        constexpr Error(Error&& other) noexcept = default;

        consteval auto operator=(const Error&) noexcept -> Error& = delete;

        consteval auto operator=(Error&&) noexcept -> Error& = delete;

        [[nodiscard]] consteval auto operator==(const Error&) const noexcept -> bool = delete;

        [[nodiscard]] consteval auto operator<=>(const Error&) const noexcept = delete;

        explicit Error(const std::size_t code) noexcept;

        explicit Error(const std::size_t code, const std::string_view command) noexcept;

        explicit Error(const std::size_t code, const std::string_view command, const std::
        string_view base) noexcept;

        auto Report() const noexcept -> void override;
    };
}

#endif
#endif