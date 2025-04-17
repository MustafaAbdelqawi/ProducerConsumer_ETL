# Data Buffer and Combiner

This project presents a simple single producer single consumer implementation using the ETL (Embedded Template Library).

## Design Overview

The core component of this solution is a template class `PacketBuffer`, which provides two primary methods:

- `bool Append(const Packet& f_packet)`
- `bool Extract(Packet& packet)`

### Key Design Considerations

- **Error Handling**  
  Methods return a boolean value to indicate success or failure, avoiding the use of exceptions for improved performance and predictability in embedded environments.

- **Pass by Reference**  
  Reference parameters are used to prevent unnecessary copying of potentially large `Packet` objects.

- **ETL Integration**  
  The implementation leverages ETL containers, which are optimized for embedded systems without dynamic memory allocation.

## Container Selection

Based on the provided task and a typical producer-consumer scenario involving multiple threads (one producer thread and one consumer thread), the `etl::queue_spsc_atomic` container has been selected. This container is suitable for the following reasons:

- **Atomic and Thread-Safe**  
  Designed for single-producer, single-consumer use cases with safe concurrent access.

- **FIFO Behavior**  
  Ensures First-In-First-Out order of packet processing.

- **Fixed Capacity**  
  Avoids dynamic memory allocation and ensures predictable resource usage.

- **Memory Efficiency**  
  Stores elements contiguously with minimal overhead.

- **Built-in Boundary Checks**  
  Prevents buffer overflows and underflows with internal full/empty state validation.

- **Deterministic Performance**  
  All operations are guaranteed to complete in constant time (O(1)), ensuring real-time performance requirements are met.

## Build
- `compile.sh -DCMAKE_BUILD_TYPE=Release` to build the tool
- `clean.sh` to clean the build

## Assumption

- **There is only Single Producer and Single Consumer in the System**

## Dependencies

- **CMake**  
  Please ensure CMake `V3.16` or higher is installed on your system to build the project.

- **ETL**

  ETL Release build `V20.40.0` is being fetched using CMAKE syntax `FetchContent_Declare` so no need to install it manually
