#include "receiver.hpp"
#include <chrono>
#include <thread>

Receiver::Receiver(std::shared_ptr<PacketBuffer> &f_buff)
{
    buffProvider = f_buff;
}

void Receiver::provide()
{
    while(true){
        Packet newPacket({{'a', 'b', 'c', 'd', 'e'}, 5});
        buffProvider->append(newPacket);
        // wait 100 millisec to simulate data collecting
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}