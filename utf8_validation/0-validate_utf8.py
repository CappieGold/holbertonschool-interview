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

# def validUTF8(data):
#     """
#     Validates if a list of integers represents a valid UTF-8 encoding.

#     Args:
#         data (list): List of integers representing bytes.

#     Returns:
#         bool: True if the data is valid UTF-8, False otherwise.
#     """
#     bytes_to_follow = 0

#     for num in data:
#         # Garder seulement les 8 bits de droite
#         byte = num & 0xFF

#         if bytes_to_follow == 0:
#             # On commence un nouveau caractère
#             if byte < 128:  # 0xxxxxxx (1 byte)
#                 continue
#             elif byte < 224:  # 110xxxxx (2 bytes)
#                 bytes_to_follow = 1
#             elif byte < 240:  # 1110xxxx (3 bytes)
#                 bytes_to_follow = 2
#             elif byte < 248:  # 11110xxx (4 bytes)
#                 bytes_to_follow = 3
#             else:
#                 # Format invalide
#                 return False
#         else:
#             # On attend un byte de continuation
#             if byte < 128 or byte >= 192:  # Doit être 10xxxxxx
#                 return False
#             bytes_to_follow -= 1

#     # Tous les caractères doivent être complets
#    return bytes_to_follow == 0
