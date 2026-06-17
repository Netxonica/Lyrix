// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_nyra_host
#define lyrix_header_guard_nyra_host
#include <optional>
#include "Nyra/System.hpp"
#include "Nyra/Architecture.hpp"

namespace Nyra
{
    class [[nodiscard]] Host final
    {
        Architecture m_arch;

        System m_sys;
    public:
        compl Host() noexcept = default;

        Host() noexcept = delete;

        Host(const Host&) noexcept = delete;

        Host(Host&&) noexcept = default;

        auto operator=(const Host&) noexcept -> Host& = delete;

        auto operator=(Host&&) noexcept -> Host& = delete;

        [[nodiscard]] auto operator<=>(const Host&) const noexcept = delete;

        [[nodiscard]] auto operator==(const Host&) const noexcept -> bool = delete;

        explicit Host(const Architecture architecture, const System system) noexcept;

        [[nodiscard]] auto architecture() const noexcept -> Architecture;

        [[nodiscard]] auto system() const noexcept -> System;
    };

    [[nodiscard]] auto Hostify() noexcept -> std::optional<Host>;
}

#endif
#endif