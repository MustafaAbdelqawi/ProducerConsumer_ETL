//
//  receiver.hpp
//
//  Created by Mustafa Abdelqawi on 17/04/25.
//  Copyright © 2025 Mustafa. All rights reserved.
//

#pragma once

#include <iostream>
#include "packet.hpp"
#include "packetbuffer.hpp"

class Receiver{
    PacketBuffer& buffer;
    public:
    explicit Receiver(PacketBuffer& f_buffer);

    // Prevent copying constructor and operator= overloading as a safety mechanism
    Receiver(const Receiver&) = delete;
    Receiver operator=(const Receiver&) = delete;

    /// @brief Function to provide 
    /// @return 
    void provide();
};