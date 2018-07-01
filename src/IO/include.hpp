#include <errno.h>
#include <netdb.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdlib.h>
#include <string.h>

#include <exception>
#include <functional>
#include <string>

#include <Failure.hpp>

#undef EOF
