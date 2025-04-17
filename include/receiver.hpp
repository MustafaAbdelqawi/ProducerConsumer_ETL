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
    std::shared_ptr<PacketBuffer> buffProvider;
    public:
    explicit Receiver(std::shared_ptr<PacketBuffer>& f_buff);

    // Prevent copying constructor and operator= overloading as a safety mechanism
    Receiver(const Receiver&) = delete;
    Receiver operator=(const Receiver&) = delete;

    /// @brief Function to provide 
    /// @return 
    void provide();
};