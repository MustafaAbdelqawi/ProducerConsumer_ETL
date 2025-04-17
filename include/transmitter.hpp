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
    std::shared_ptr<PacketBuffer> buffTransmitter;
public:
    /// @brief 
    /// @param f_buffer 
    explicit Transmitter(std::shared_ptr<PacketBuffer>& f_buffer);

    Transmitter(const Transmitter&) = delete;
    Transmitter operator=(const Transmitter&) = delete;

    /// @brief Function to Extract packet from Buffer
    /// @return 
    void receive();
};
