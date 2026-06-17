// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_lumina_error
#define lyrix_header_guard_lumina_error
#include <cstddef>

namespace Lumina
{
    class [[nodiscard]] Error
    {
        const std::size_t m_code;
    public:
        constexpr virtual compl Error() noexcept = default;

        explicit consteval Error() noexcept = delete;

        explicit consteval Error(const Error&) noexcept = delete;

        constexpr Error(Error&& other) noexcept = default;

        consteval auto operator=(const Error&) noexcept -> Error& = delete;

        consteval auto operator=(Error&&) noexcept -> Error& = delete;

        [[nodiscard]] consteval auto operator==(const Error&) const noexcept -> bool = delete;

        [[nodiscard]] consteval auto operator<=>(const Error&) const noexcept = delete;

        explicit Error(const std::size_t code) noexcept;

        [[nodiscard]] auto code() const noexcept -> std::size_t;

        virtual auto Report() const noexcept -> void = 0;
    };
}

#endif
#endif