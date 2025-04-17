#include "packetbuffer.hpp"

bool
PacketBuffer::append(const Packet& f_packet){
    if(buff.full()){
        std::cout << "The buffer is Full, Can not add new Packets....!\n";
        return false;
    } 
    buff.push(f_packet);
    std::cout << "Buffer appended Successfully...!\n";
    return true;
}

bool
PacketBuffer::extract (Packet& packet){
    if(buff.empty()){
        std::cout << "The buffer is Empty, Can not extract any Packets....!\n";
        return false;
    }
    buff.pop(packet);
    std::cout << "Buffer extracted Successfully...!\n";
    return true;
}

size_t
PacketBuffer::getBufferSize() const{
    return buff.size();
}
