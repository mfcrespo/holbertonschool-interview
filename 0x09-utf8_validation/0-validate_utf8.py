#!/usr/bin/python3
""" method that determines if a given data set
    represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """ determines if a given data set represents a valid UTF-8 encoding.
    """
    # Use maks, to clean byte of anything beyond 8 least significant bits.
    cleanByte = [rawByte & 0b11111111 for rawByte in data]

    # Cast to byte type.
    byte = bytes(cleanByte)

    # Attempt to decode byte data.
    try:
        byte.decode()
    except UnicodeDecodeError:
        # If decoding fails, return False.
        return False

    return True
