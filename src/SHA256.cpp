#include "SHA256.h"
#include <cstring>
#include <sstream>
#include <iomanip>

constexpr std::array<uint32_t, 64> SHA256::K;

SHA256::SHA256() : block_len_(0), bit_len_(0)
{
    H[0] = 0x6a09e667;
    H[1] = 0xbb67ae85;
    H[2] = 0x3c6ef372;
    H[3] = 0xa54ff53a;
    H[4] = 0x510e527f;
    H[5] = 0x9b05688c;
    H[6] = 0x1f83d9ab;
    H[7] = 0x5be0cd19;
}

void SHA256::update(const uint8_t *data, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        data_[block_len_++] = data[i];
        if (block_len_ == 64)
        {
            ProcessBlock();

            // End of the block
            bit_len_ += 512;
            block_len_ = 0;
        }
    }
}

void SHA256::update(const std::string &data)
{
    update(reinterpret_cast<const uint8_t *>(data.c_str()), data.size());
}

uint8_t *SHA256::digest()
{
    uint8_t *hash = new uint8_t[32];

    Pad();
    Reverse(hash);

    return hash;
}

uint32_t SHA256::Rotr(uint32_t x, uint32_t n)
{
    return (x >> n) | (x << (32 - n));
}

uint32_t SHA256::Ch(uint32_t e, uint32_t f, uint32_t g)
{
    return (e & f) ^ (~e & g);
}

uint32_t SHA256::Maj(uint32_t a, uint32_t b, uint32_t c)
{
    return (a & b) ^ (a & c) ^ (b & c);
}

uint32_t SHA256::Ssig0(uint32_t x)
{
    return SHA256::Rotr(x, 7) ^ SHA256::Rotr(x, 18) ^ (x >> 3);
}

uint32_t SHA256::Ssig1(uint32_t x)
{
    return SHA256::Rotr(x, 17) ^ SHA256::Rotr(x, 19) ^ (x >> 10);
}

uint32_t SHA256::Lsig0(uint32_t x)
{
    return SHA256::Rotr(x, 2) ^ SHA256::Rotr(x, 13) ^ SHA256::Rotr(x, 22);
}

uint32_t SHA256::Lsig1(uint32_t x)
{
    return SHA256::Rotr(x, 6) ^ SHA256::Rotr(x, 11) ^ SHA256::Rotr(x, 25);
}

void SHA256::ProcessBlock()
{
    uint32_t W[64];
    uint32_t a, b, c, d, e, f, g, h;

    for (uint8_t i = 0; i < 64; i += 4)
    {
        W[i / 4] = (data_[i] << 24) | (data_[i + 1] << 16) | (data_[i + 2] << 8) | (data_[i + 3]);
    }

    for (uint8_t k = 16; k < 64; k++)
    { // Remaining 48 blocks
        W[k] = SHA256::Ssig1(W[k - 2]) + W[k - 7] + SHA256::Ssig0(W[k - 15]) + W[k - 16];
    }

    a = H[0];
    b = H[1];
    c = H[2];
    d = H[3];
    e = H[4];
    f = H[5];
    g = H[6];
    h = H[7];

    for (uint8_t i = 0; i < 64; i++)
    {
        uint32_t t1 = h + SHA256::Lsig1(e) + SHA256::Ch(e, f, g) + K[i] + W[i];
        uint32_t t2 = SHA256::Lsig0(a) + SHA256::Maj(a, b, c);

        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    H[0] += a;
    H[1] += b;
    H[2] += c;
    H[3] += d;
    H[4] += e;
    H[5] += f;
    H[6] += g;
    H[7] += h;
}

void SHA256::Pad()
{

    uint64_t i = block_len_;
    uint8_t end = block_len_ < 56 ? 56 : 64;

    data_[i++] = 0x80; // Append a bit 1
    while (i < end)
    {
        data_[i++] = 0x00; // Pad with zeros
    }

    if (block_len_ >= 56)
    {
        ProcessBlock();
        memset(data_, 0, 56);
    }

    // Append to the Padding the total message's length in bits and transform.
    bit_len_ += block_len_ * 8;
    data_[63] = bit_len_;
    data_[62] = bit_len_ >> 8;
    data_[61] = bit_len_ >> 16;
    data_[60] = bit_len_ >> 24;
    data_[59] = bit_len_ >> 32;
    data_[58] = bit_len_ >> 40;
    data_[57] = bit_len_ >> 48;
    data_[56] = bit_len_ >> 56;
    ProcessBlock();
}

void SHA256::Reverse(uint8_t *hash)
{
    // SHA uses big endian byte ordering
    // Revert all bytes
    for (uint8_t i = 0; i < 4; i++)
    {
        for (uint8_t j = 0; j < 8; j++)
        {
            hash[i + (j * 4)] = (H[j] >> (24 - i * 8)) & 0x000000ff;
        }
    }
}

std::string SHA256::toString(const uint8_t *digest)
{
    std::stringstream s;
    s << std::setfill('0') << std::hex;

    for (uint8_t i = 0; i < 32; i++)
    {
        s << std::setw(2) << (unsigned int)digest[i];
    }

    return s.str();
}