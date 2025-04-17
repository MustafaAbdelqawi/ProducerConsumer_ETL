//
//  packet.hpp
//  Playing
//
//  Created by Mustafa Abdelqawi on 16/04/25.
//  Copyright © 2025 Mustafa. All rights reserved.
//

#pragma once

#include <iostream>

constexpr unsigned maxPacketSize = 123u;
struct Packet {
    u_char data[maxPacketSize];  // packet data
    uint8_t size;                // size of data
};