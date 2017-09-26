#ifndef _POLLER_HPP_
#define _POLLER_HPP_


#include "sys/epoll.h"
#include "sys/types.h"
#include "channel.hpp"
#include "socket.hpp"
#include "../include/debug_new.hpp"

namespace Network{

    enum { MaxEvents = 1204 };

    class Poller
    {
    public:
        Poller();
        ~Poller();

        void RegisterChannel(Channel*);
        void UnregisterChannel(Channel*);
        void BackendPoll(int ms);
    private:
        int fd_;
        struct epoll_event events_[MaxEvents];
    };
}   

#endif //_POLLER_HPP_
