#include "transmitter.hpp"
#include <chrono>
#include <thread>

Transmitter::Transmitter(std::shared_ptr<PacketBuffer> &f_buffer)
{
    buffTransmitter = f_buffer;
}

void Transmitter::receive()
{
    while (true)
    {
        Packet receivedPacket;
        buffTransmitter->extract(receivedPacket);
    
        std::cout << "Received Packet: " << std::endl;
    
        for (uint8_t i = 0; i < receivedPacket.size; ++i)
        {
            std::cout << receivedPacket.data[i] << " ";
        }
    
        std::cout << std::endl;
    
        // wait 100 millisec to simulate data processing
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}