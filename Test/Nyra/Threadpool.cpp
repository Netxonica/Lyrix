// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/Threadpool.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    std::atomic_size_t counter = 0uz;
    const std::size_t limit = std::thread::hardware_concurrency();
    {
        Nyra::Threadpool pool{static_cast<const std::uint32_t>(limit)};
        for(std::size_t i = 0uz; i < limit; ++i)
            pool += [&counter]
            {
                ++counter;
            };
    }
    return counter == limit;
}

int main()
{
    return not lyrix_test();
}

#endif