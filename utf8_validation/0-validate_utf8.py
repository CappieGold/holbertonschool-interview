#!/usr/bin/python3
"""
UTF-8 Validation
"""


def validUTF8(data):
    """
    Validates if a list of integers represents a valid UTF-8 encoding.

    Args:
        data (list): List of integers representing bytes.

    Returns:
        bool: True if the data is valid UTF-8, False otherwise.
    """
    num_bytes = 0

    for byte in data:
        # Keep only the 8 least significant bits
        byte = byte & 0xFF

        if num_bytes == 0:
            if (byte >> 7) == 0b0:  # 1-byte character
                continue
            elif (byte >> 5) == 0b110:  # 2-byte character
                num_bytes = 1
            elif (byte >> 4) == 0b1110:  # 3-byte character
                num_bytes = 2
            elif (byte >> 3) == 0b11110:  # 4-byte character
                num_bytes = 3
            else:
                return False
        else:
            if (byte >> 6) != 0b10:  # Continuation byte must start with '10'
                return False
            num_bytes -= 1

    return num_bytes == 0
