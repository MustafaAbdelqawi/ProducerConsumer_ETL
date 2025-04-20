//
//  packetbuffer.hpp
//  Playing
//
//  Created by Mustafa Abdelqawi on 16/04/25.
//  Copyright © 2025 Mustafa. All rights reserved.
//

#include <iostream>
#include "packetbuffer.hpp"
#include <receiver.hpp>
#include <transmitter.hpp>
#include <thread>

int main(){

    PacketBuffer buffer;

    Transmitter transmitter(buffer);
    Receiver receiver(buffer);
    
    std::thread t1(&Transmitter::receive, &transmitter);
    std::thread t2(&Receiver::provide, &receiver);

    t1.join();
    t2.join();

    // Packet p1 {{'a', 'b'}, 2};
    // Packet p2 {{'d', 'e', 'f'}, 3};
    // Packet p3 {{'g', 'h', 'i', 'j'}, 4};

    // buffer.append(p1);

    // buffer.append(p2);

    // buffer.append(p3);

    // Packet extracted;
    // if(buffer.extract(extracted)){
    //     for(uint8_t i = 0; i < extracted.size; ++i){
    //         std::cout << extracted.data[i] << " ";
    //     }

    //     std::cout << std::endl;
    // }


    // if(buffer.extract(extracted)){
    //     for(uint8_t i = 0; i < extracted.size; ++i){
    //         std::cout << extracted.data[i] << " ";
    //     }

    //     std::cout << std::endl;
    // }

    // std::cout << "Current buffer Size is: " << buffer.getBufferSize() << std::endl;

    return 0;
}