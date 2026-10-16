// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/Process.hpp"
#ifndef lyrix_windows
#include <fcntl.h>
#include <sys/wait.h>
#endif
#include <cerrno>
#include <memory>
#include <cstdlib>
#include <optional>
#include "Nyra/Error.hpp"

namespace Nyra
{
    Process::compl Process() noexcept
    {
        if(not m_transfer)
        {
            #ifdef lyrix_windows
            const DWORD state = WaitForSingleObject(m_id.hProcess, INFINITE);
            if(state == WAIT_FAILED or state == WAIT_ABANDONED)
                std::abort();
            if(CloseHandle(m_id.hThread) == 0)
                std::abort();
            if(CloseHandle(m_id.hProcess) == 0)
                std::abort();
            if(CloseHandle(streams()[0uz]) == 0)
                std::abort();
            if(CloseHandle(streams()[3uz]) == 0)
                std::abort();
            #else
            if(id() not_eq 0 and id() not_eq -1)
            {
                int status{};
                pid_t result{};
                do
                {
                    result = waitpid(id(), &status, 0);
                }
                while(result == -1 && errno == EINTR);
                if(result == id())
                {
                    if(WIFEXITED(status))
                    {
                        if(WEXITSTATUS(status) == 0)
                        {
                            if(close(streams()[0uz]) == -1)
                                std::make_unique<Error>(25uz)->Report();
                            if(close(streams()[1uz]) == -1)
                                std::make_unique<Error>(25uz)->Report();
                        }
                        else
                            std::abort();
                    }
                    else if(WIFSIGNALED(status))
                        std::abort();
                }
            }
            #endif
        }
    }

    auto Process::valid() noexcept -> void
    {
        m_transfer = false;
    }

    #ifdef lyrix_windows
    [[nodiscard]] auto Process::streams() const noexcept -> const HANDLE(&)[4uz]
    {
        return m_pipes;
    }

    [[nodiscard]] auto Process::streams() noexcept -> HANDLE(&)[4uz]
    {
        return m_pipes;
    }

    [[nodiscard]] auto Process::id() const noexcept -> const PROCESS_INFORMATION&
    {
        return m_id;
    }

    [[nodiscard]] auto Process::id() noexcept -> PROCESS_INFORMATION&
    {
        return m_id;
    }
    #else
    [[nodiscard]] auto Process::streams() const noexcept -> const int(&)[2uz]
    {
        return m_pipes;
    }

    [[nodiscard]] auto Process::streams() noexcept -> int(&)[2uz]
    {
        return m_pipes;
    }

    [[nodiscard]] auto Process::id() const noexcept -> const pid_t&
    {
        return m_id;
    }

    [[nodiscard]] auto Process::id() noexcept -> pid_t&
    {
        return m_id;
    }
    #endif
    [[nodiscard]] auto Process::read(std::string&) noexcept -> bool
    {
        #ifdef lyrix_windows
        #else
        #endif
        return true;
    }

    [[nodiscard]] auto Process::write(std::string) noexcept -> bool
    {
        #ifdef lyrix_windows
        #else
        #endif
        return true;
    }

    [[nodiscard]] auto create_process(const char* name, std::vector<std::string> arguments)
    noexcept -> std::optional<Process>
    {  
        char* path = std::getenv(name);
        if(path == nullptr)
        {
            std::make_unique<Error>(21uz, name)->Report();
            return std::nullopt;
        }
        Process process;
        #ifdef lyrix_windows
        SECURITY_ATTRIBUTES security;
        security.nLength = sizeof(SECURITY_ATTRIBUTES);
        security.lpSecurityDescriptor = nullptr;
        security.bInheritHandle = TRUE;
        if(CreatePipe(&process.streams()[0uz], &process.streams()[1uz], &security, 0) == 0)
        {
            std::make_unique<Error>(23uz, name)->Report();
            return std::nullopt;
        }
        if(SetHandleInformation(process.streams()[0uz], HANDLE_FLAG_INHERIT, 0) == 0)
        {
            std::make_unique<Error>(23uz, name)->Report();
            return std::nullopt;
        }
        if(CreatePipe(&process.streams()[2uz], &process.streams()[3uz], &security, 0) == 0)
        {
            std::make_unique<Error>(23uz, name)->Report();
            return std::nullopt;
        }
        if(SetHandleInformation(process.streams()[3uz], HANDLE_FLAG_INHERIT, 0) == 0)
        {
            std::make_unique<Error>(23uz, name)->Report();
            return std::nullopt;
        }
        std::string argv;
        argv += path;
        for(const std::string& argument : arguments)
        {
            argv.append(1uz, ' ');
            argv += argument;
        }
        STARTUPINFO info;
        info.cb = sizeof(STARTUPINFO);
        info.lpReserved = NULL;
        info.lpDesktop = 0;
        info.lpTitle = 0;
        info.dwX = 0;
        info.dwY = 0;
        info.dwXSize = 0;
        info.dwYSize = 0;
        info.dwXCountChars = 0;
        info.dwYCountChars = 0;
        info.dwFillAttribute = 0;
        info.dwFlags = STARTF_USESTDHANDLES;
        info.wShowWindow = 0;
        info.cbReserved2 = 0;
        info.lpReserved2 = NULL;
        info.hStdInput = process.streams()[2uz];
        info.hStdError = process.streams()[1uz];
        info.hStdOutput = process.streams()[1uz];
        if(CreateProcess(path, argv.data(), NULL, NULL, TRUE, 0, NULL, NULL, &info, &process.id())
        == 0)
        {
            std::make_unique<Error>(24uz, name)->Report();
            return std::nullopt;
        }
        if(CloseHandle(process.streams()[1uz]) == 0)
        {
            std::make_unique<Error>(25uz)->Report();
            return std::nullopt;
        }
        if(CloseHandle(process.streams()[2uz]) == 0)
        {
            std::make_unique<Error>(25uz)->Report();
            return std::nullopt;
        }
        process.valid();
        return process;
        #else
        if(pipe2(process.streams(), 0) == -1)
        {
            std::make_unique<Error>(22uz)->Report();
            return std::nullopt;
        }
        int child_streams[2uz];
        if(pipe2(child_streams, 0) == -1)
        {
            std::make_unique<Error>(23uz, name)->Report();
            return std::nullopt;
        }
        switch(process.id() = fork())
        {
            case -1:
                std::make_unique<Error>(24uz, name)->Report();
                return std::nullopt;
            case 0:
                if(close(process.streams()[1uz]) == -1)
                {
                    std::make_unique<Error>(25uz)->Report();
                    return std::nullopt;
                }
                if(close(child_streams[0uz]) == -1)
                {
                    std::make_unique<Error>(25uz)->Report();
                    return std::nullopt;
                }
                if(dup3(process.streams()[0uz], STDIN_FILENO, 0) == -1)
                {
                    std::make_unique<Error>(25uz)->Report();
                    return std::nullopt;
                }
                if(dup3(child_streams[1uz], STDOUT_FILENO, 0) == -1)
                {
                    std::make_unique<Error>(25uz)->Report();
                    return std::nullopt;
                }
                if(close(process.streams()[0uz]) == -1)
                {
                    std::make_unique<Error>(25uz)->Report();
                    return std::nullopt;
                }
                if(close(child_streams[1uz]) == -1)
                {
                    std::make_unique<Error>(25uz)->Report();
                    return std::nullopt;
                }
                {
                    std::vector<char*> argv;
                    argv.emplace_back(path);
                    for(auto& argument : arguments)
                        argv.emplace_back(argument.data());
                    argv.emplace_back(nullptr);
                    if(execv(path, argv.data()) == -1)
                        std::abort();
                    return Process{};
                }
            break;
            default:
                if(close(process.streams()[0uz]) == -1)
                {
                    std::make_unique<Error>(25uz)->Report();
                    return std::nullopt;
                }
                if(close(child_streams[1uz]) == -1)
                {
                    std::make_unique<Error>(25uz)->Report();
                    return std::nullopt;
                }
                process.streams()[0uz] = process.streams()[1uz];
                process.streams()[1uz] = child_streams[0uz];
                process.valid();
                return process;
        }
        #endif
    }
}

#endif