//
//  transmitter.hpp
//
//  Created by Mustafa Abdelqawi on 17/04/25.
//  Copyright © 2025 Mustafa. All rights reserved.
//
#pragma once

#include <iostream>
#include "packet.hpp"
#include "packetbuffer.hpp"

class Transmitter
{
private:
    PacketBuffer& buffer;
public:
    /// @brief 
    /// @param f_buffer 
    explicit Transmitter(PacketBuffer& f_buffer);

    Transmitter(const Transmitter&) = delete;
    Transmitter operator=(const Transmitter&) = delete;

    /// @brief Function to Extract packet from Buffer
    /// @return 
    void receive();
};
