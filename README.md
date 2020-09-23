# DPP
A C++ Library interfacing Discord API, or should i say... C++ Discord API Wrapper.

## Dependencies
- [JSON](https://github.com/nlohmann/json)
- [Boost::asio](https://www.boost.org/)
- [Boost::system](https://www.boost.org/)
- [Boost::date_time](https://www.boost.org/)
- [OpenSSL](https://www.openssl.org/)
- [cpprest](https://github.com/microsoft/cpprestsdk)
- [websocketpp](https://github.com/zaphoyd/websocketpp)

## Installation
```
vcpkg install nlohmann-json
vcpkg install cpprestsdk
vcpkg install boost

git clone https://github.com/discord-cpp/discord.cpp
cd discord.cpp
mkdir build && cd build
vcpkg integrate install
cmake .. -DCMAKE_TOOLCHAIN_FILE=/use/what/integrate/install/gives
make
```

## Usage
```cpp
#include "attachment.hpp"
#include "bot.hpp"
#include "context.hpp"
#include "embedbuilder.hpp"
#include "events.hpp"
#include "member.hpp"
#include "role.hpp"
#include "user.hpp"
#include "utils.hpp"
#include "emoji.hpp"
#include "message.hpp"

int main() {
    discord::Bot bot{ "tokenhere", ">" };

    bot.register_callback<discord::events::ready>([&bot]() {
        std::cout << "Ready!" << std::endl
             << "Logged in as: " << bot.username << "#" << bot.discriminator
             << std::endl
             << "ID: " << bot.id << std::endl
             << "-----------------------------" << std::endl;
    });

    bot.register_command("ping", "Ping?", {}, [](discord::Context ctx) {
        ctx.channel->send("pong!")
            .wait();
    }, {});

    return bot.run();
}
```

```
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
```
