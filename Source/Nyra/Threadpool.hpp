// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_nyra_threadpool
#define lyrix_header_guard_nyra_threadpool
#include <mutex>
#include <atomic>
#include <vector>
#include <thread>
#include <functional>
#include <condition_variable>

namespace Nyra
{
    class [[nodiscard]] Threadpool final
    {
        std::atomic_bool m_finish = false;

        std::condition_variable m_locker;

        std::mutex m_mutex;

        std::vector<std::thread> m_threads;

        std::vector<std::function<void()>> m_tasks;
    public:
        ~Threadpool() noexcept;

        Threadpool(const std::uint32_t workers) noexcept;

        auto operator+=(std::function<void()> task) noexcept -> void;

        [[nodiscard]] auto Workers() const noexcept -> std::size_t;

        [[nodiscard]] auto Mutex() noexcept -> std::mutex&;

        [[nodiscard]] auto Locker() noexcept -> std::condition_variable&;

        [[nodiscard]] auto Finish() const noexcept -> const std::atomic_bool&;

        [[nodiscard]] auto Empty() const noexcept -> bool;

        [[nodiscard]] auto Tasks() noexcept -> std::vector<std::function<void()>>&;
    };
}

#endif
#endif