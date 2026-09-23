#pragma once
#include <cstdint>

#pragma pack(push, 1)
struct PacketHeader {
    uint32_t magic;       // e.g., 0x53435354 ("SCST")
    uint32_t frameIndex;  // Sequential frame counter
    uint32_t payloadSize; // Size of following H.264 NAL units
    uint64_t timestampNs; // For glass-to-glass latency calculations
};
#pragma pack(pop)