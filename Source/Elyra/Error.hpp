// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_elyra_error
#define lyrix_header_guard_elyra_error
#include <string_view>
#include "Lumina/Error.hpp"

namespace Elyra
{
    class [[nodiscard]] Error final : public Lumina::Error
    {
        std::string_view m_file;
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

        auto operator=(const std::string_view file) noexcept -> void;

        auto Report() const noexcept -> void override;
    };
}

#endif
#endif