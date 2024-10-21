#include <iostream>

inline void hilbert_rotate3D(unsigned n, unsigned x, unsigned y, unsigned z, unsigned rx, unsigned ry, unsigned rz) {
    if (rz == 0) {
        if (ry == 0) {
            std::swap(x, y);
        }
        if (rx == 0) {
            x = n - 1 - x;
            y = n - 1 - y;
        }
    } else if (rz == 1) {
        if (rx == 0) {
            std::swap(x, z);
        }
        if (ry == 0) {
            x = n - 1 - x;
            z = n - 1 - z;
        }
    }
}

inline unsigned hilbert_encode(unsigned n, unsigned x, unsigned y, unsigned z) {
    unsigned int index = 0;
    unsigned rx, ry, rz;

    for (unsigned s = n / 2; s > 0; s /= 2) {
        rx = (x & s) > 0;
        ry = (y & s) > 0;
        rz = (z & s) > 0;

        index = index * 8 + rz * 4 + ry * 2 + rx;;

        hilbert_rotate3D(s, x, y, z, rx, ry, rz);
    }

    return index;
}