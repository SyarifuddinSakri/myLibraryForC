#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Convert string IP address to numerical representation
uint32_t ipStringToUint32(const char *ipString) {
    uint32_t result = 0;
    int values[4];

    // Ensure ipString is not NULL
    if (ipString == NULL) {
        fprintf(stderr, "Error: NULL pointer passed to ipStringToUint32.\n");
        return result;
    }

    // Validate and parse the IP address
    if (sscanf(ipString, "%d.%d.%d.%d", &values[0], &values[1], &values[2], &values[3]) == 4) {
        // Validate each segment
        for (int i = 0; i < 4; i++) {
            if (values[i] < 0 || values[i] > 255) {
                fprintf(stderr, "Error: Invalid value in IP address segment.\n");
                return result;
            }
        }

        // Combine the segments into a single uint32_t value
        result = (values[0] << 24) | (values[1] << 16) | (values[2] << 8) | values[3];
    } else {
        fprintf(stderr, "Error: Invalid IP address format.\n");
    }

    return result;
}

// Convert numerical representation to string IP address
void uint32ToIpString(uint32_t ipAddress, char *ipString) {
    if (ipString == NULL) {
        fprintf(stderr, "Error: NULL pointer passed to uint32ToIpString.\n");
        return;
    }

    // Extract each segment of the IP address
    int segment1 = (ipAddress >> 24) & 0xFF;
    int segment2 = (ipAddress >> 16) & 0xFF;
    int segment3 = (ipAddress >> 8) & 0xFF;
    int segment4 = ipAddress & 0xFF;

    // Format the string
    sprintf(ipString, "%d.%d.%d.%d", segment1, segment2, segment3, segment4);
}

int main() {
    const char ipaddress[] = "192.168.100.23";
    uint32_t result = ipStringToUint32(ipaddress);

    if (result != 0) {
        // Print the result
        printf("Numerical representation: %u\n", result);
    } else {
        fprintf(stderr, "Conversion failed. Check error messages.\n");
    }

        char ipString[16]; // Assuming IPv4 addresses can be at most 15 characters long

    // Convert numerical IP to string
    uint32_t numericalIp = ipStringToUint32(ipaddress);
    uint32ToIpString(numericalIp, ipString);

    // Print the result
    printf("IP Address in string representation: %s\n", ipString);

    return 0;
}
