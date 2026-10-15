// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_nyra_process
#define lyrix_header_guard_nyra_process
#ifdef lyrix_windows
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <vector>
#include <optional>

namespace Nyra
{
    class [[nodiscard]] Process final
    {
        bool m_transfer = true;
        #ifdef lyrix_windows
        HANDLE m_pipes[4uz];

        PROCESS_INFORMATION m_id;
        #else
        int m_pipes[2uz];

        pid_t m_id;
        #endif
    public:
        compl Process() noexcept;

        explicit constexpr Process() noexcept = default;

        explicit consteval Process(const Process&) noexcept = delete;

        constexpr Process(Process&& other) noexcept : m_transfer(other.m_transfer), m_id(other.m_id
        )
        {
            other.m_transfer = true;
            for(std::size_t i = 0uz; i <
            #ifdef lyrix_windows
            4
            #else
            2
            #endif
            ; ++i)
                m_pipes[i] = other.m_pipes[i];
        }

        consteval auto operator=(const Process&) noexcept -> Process& = delete;

        consteval auto operator=(Process&&) noexcept -> Process& = delete;

        [[nodiscard]] consteval auto operator==(const Process&) const noexcept -> bool = delete;

        [[nodiscard]] consteval auto operator<=>(const Process&) const noexcept = delete;

        auto valid() noexcept -> void;

        #ifdef lyrix_windows
        [[nodiscard]] auto streams() const noexcept -> const HANDLE(&)[4uz];

        [[nodiscard]] auto streams() noexcept -> HANDLE(&)[4uz];

        [[nodiscard]] auto id() const noexcept -> const PROCESS_INFORMATION&;

        [[nodiscard]] auto id() noexcept -> PROCESS_INFORMATION&;
        #else
        [[nodiscard]] auto streams() const noexcept -> const int(&)[2uz];

        [[nodiscard]] auto streams() noexcept -> int(&)[2uz];

        [[nodiscard]] auto id() const noexcept -> const pid_t&;

        [[nodiscard]] auto id() noexcept -> pid_t&;
        #endif
        [[nodiscard]] auto read() noexcept -> std::string;

        [[nodiscard]] auto write(std::string content) noexcept -> bool;
    };

    [[nodiscard]] auto create_process(const char* name, std::vector<std::string> arguments)
    noexcept -> std::optional<Process>;
}

#endif
#endif