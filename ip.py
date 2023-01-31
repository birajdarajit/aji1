def ip_to_bin(ip_address):
    octets = ip_address.split('.')
    binary_ip = ''
    for octet in octets:
        binary_octet = bin(int(octet))[2:].zfill(8)
        binary_ip += binary_octet
    return binary_ip

ip_address = '192.168.0.1'
binary_ip = ip_to_bin(ip_address)
print(binary_ip)
