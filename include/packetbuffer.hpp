//
//  packetbuffer.hpp
//
//  Created by Mustafa Abdelqawi on 16/04/25.
//  Copyright © 2025 Mustafa. All rights reserved.
//

#pragma once
#include <iostream>
#include "packet.hpp"
#include <etl/queue_spsc_atomic.h>

constexpr size_t MAXIMUM_CAPACITY = 10;

class PacketBuffer{
    // atomic etl queue for multi-threaded application, for testing purposes the maximum capacity of the queue is set to 10
    etl::queue_spsc_atomic<Packet, MAXIMUM_CAPACITY> buff;

    public:

    /// @brief default constructor
    PacketBuffer() = default;

    // Prevent copying constructor and operator= overloading as a safety mechanism
    PacketBuffer(const PacketBuffer&) = delete;
    PacketBuffer& operator=(const PacketBuffer&) = delete;

    /// @brief function to append packet to a buffer
    /// @param f_packet : packet to be appended
    /// @return true if successful, false if buffer is full
    bool append(const Packet& f_packet);

    /// @brief Function to extract packet from buffer
    /// @param f_packet : packet to be extracted
    /// @return true if successful (packet contains data), false if buffer is empty
    bool extract (Packet& packet);

    /// @brief Function to get the current size of buffer for testing purposes only
    /// @return current buffer size or length
    size_t getBufferSize()const;
};