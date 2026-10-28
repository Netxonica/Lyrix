// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_shutdown
#define lyrix_header_guard_eura_shutdown
#include <string>
#include <atomic>
#include <variant>

namespace Eura
{
    [[nodiscard]] auto Shutdown(const std::variant<std::int32_t, std::string>& id, std::atomic_bool
    & ready_to_close) noexcept -> std::string;
}

#endif
#endif