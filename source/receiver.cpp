#include "receiver.hpp"
#include <chrono>
#include <thread>

Receiver::Receiver(PacketBuffer& f_buffer) : buffer(f_buffer)
{
    //buffProvider = f_buff;
}

void Receiver::provide()
{
    while(true){
        Packet newPacket({{'a', 'b', 'c', 'd', 'e'}, 5});
        buffer.append(newPacket);
        // wait 100 millisec to simulate data collecting
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}