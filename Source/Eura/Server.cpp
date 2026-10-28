// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Server.hpp"
#include <iostream>
#include "Eura/Client.hpp"
#include "Eura/Shutdown.hpp"
#include "Eura/Initialize.hpp"
#include "Nyra/Threadpool.hpp"
#include "Eura/WindowShowMessage.hpp"
#include "Eura/NotificationMessage.hpp"

namespace Eura
{
    [[nodiscard]] static auto Body() noexcept -> std::string
    {
        std::size_t size = 0uz;
        {
            std::string line;
            bool header_done = false;
            while(size == 0uz or not header_done)
                while(std::getline(std::cin, line))
                {
                    if(line == "\r")
                    {
                        header_done = true;
                        break;
                    }
                    static constexpr std::string_view content_length = "Content-Length: ",
                    content_type = "Content-Type: ";
                    line.pop_back();
                    if(line.starts_with(content_length))
                        size = std::stoull(line.substr(content_length.size()));
                    else if(line.starts_with(content_type))
                    {
                        const std::string type = line.substr(content_type.size());
                        if(not type.ends_with("charset=utf-8") and not type.ends_with(
                        "charset=utf8"))
                            std::abort();
                    }
                    else
                        std::abort();
                }
        }
        if(std::cin.eof())
            std::abort();
        std::string message;
        message.resize_and_overwrite(size, [&](char* data, const std::size_t size)
        {
            std::cin.read(data, static_cast<std::streamsize>(size));
            return size;
        });
        if(std::cin.bad() or (static_cast<std::size_t>(std::cin.gcount()) not_eq size))
            std::abort();
        return message;
    }

    [[noreturn]] auto Listen() noexcept -> void
    {
        std::atomic<Initialization> initialization = Initialization::Uninitialized;
        std::atomic_bool close = false, ready_to_close = false;
        {
            Nyra::Threadpool pool{std::thread::hardware_concurrency()};
            while(not close)
            {
                std::string body = Body();
                pool += [body = std::move(body), &initialization, &ready_to_close, &close, &pool]
                {
                    const nlohmann::json message = nlohmann::json::parse(body);
                    if(message.contains("id"))
                    {
                        RequestMessage request_message;
                        from_json(message, request_message);
                        if(request_message.jsonrpc not_eq "2.0")
                            std::abort();
                        switch(initialization)
                        {
                            case Initialization::Initialized:
                                if(request_message.method == "shutdown")
                                    Client(pool.Mutex(), Shutdown(request_message.id,
                                    ready_to_close));
                            break;
                            case Initialization::Initializing:
                            break;
                            case Initialization::Uninitialized:
                                Initialize(pool.Mutex(), request_message, initialization);
                        }
                    }
                    else
                    {
                        NotificationMessage notification_message;
                        from_json(message, notification_message);
                        if(notification_message.jsonrpc not_eq "2.0")
                            std::abort();
                        switch(initialization)
                        {
                            case Initialization::Initialized:
                                if(notification_message.method == "exit")
                                    close.store(true);
                            break;
                            case Initialization::Initializing:
                                if(notification_message.method == "initialized")
                                {
                                    WindowShowMessage(pool.Mutex(), MessageType::Info, "Hello~!");
                                    initialization.store(Initialization::Initialized);
                                }
                            break;
                            case Initialization::Uninitialized:
                            break;
                        }
                    }
                };
            }
        }
        std::exit(ready_to_close.load() ? 0 : 1);
    }
}

#endif