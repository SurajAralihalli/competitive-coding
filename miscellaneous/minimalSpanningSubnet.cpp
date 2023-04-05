#include <bits/stdc++.h>
// #include <vector>
// #include <iostream>
using namespace std;

/* Input: vector of VALID ip addresses
 * Output: subnet
*/
string minimal_spanning_subnet(vector<string> ip_set) {
    
    if(ip_set.size()==0) return "no input";
    
    unsigned char count;
    string token;

    unsigned int bitstring; // stores the 32 bit ip address as a bitstring
    unsigned int and_ips = 0xFFFFFFFF;
    unsigned int or_ips = 0;

    for( auto ip : ip_set) { // iterate over the list of ip addresses
        
        stringstream ss(ip);
        token = "";
        bitstring = 0;
        count = 3;
        while ( getline(ss, token, '.') ) {  // generate the binary bitstring as unsigned int from the . separeted ip string
            bitstring = bitstring + (stoi(token) << count * 8);
            count--;
        }
        
        and_ips = and_ips & bitstring; // bitwise AND of all the ip addresses
        or_ips = or_ips | bitstring;  // bitwise OR of all the ip addresses

    }
    
    unsigned char subnet = 0; // using unsigned char instead of int to save space
    unsigned char i_and; 
    unsigned char i_or;
    for (int i = 0; i<32; i++) { // find the length of longest common prefix in O(1) time
        i_and = (and_ips & (1 << (31 - i))) >> (31 - i);
        i_or = (or_ips & (1 << (31 - i))) >> (31 - i);

        if(i_and == 1) {
            subnet++;
        }
        else if(i_or == 0) {
            subnet++;
        }
        else {
            break;
        }
    }

    unsigned int subnet_mask = 0xFFFFFFFF << (32 - subnet);  // minimal spanning subnet mask
    unsigned int subnet_ip = bitstring & subnet_mask; // construct the subnet ip using the subnet mask
    
    // generate human readable ip address string from the bitstring (here bitstring is stored as unsigned int)
    string ip = to_string((subnet_ip & 0xFF000000) >> 24) + "." + to_string((subnet_ip & 0x00FF0000)>>16) + "." + to_string((subnet_ip & 0x0000FF00)>>8) + "." + to_string(subnet_ip & 0x000000FF);

    ip = ip + "/" + to_string(subnet);
    
    return ip;
}

/*
 * Time complexity : O(n) where n is the number of ip addresses provided as the input
 * Space complexity : O(1)
 * 
 * Optimizations: 
 * Program is optimized to save space by using unsigned int to store ip addresses.
 * unsigned char is used instead of int to store numbers less than 255 (example: subnet, i_and)
 * bitwise operations are used to find the longest common prefix instead of linear comparision of bits in the ip bitstring
*/

int main() {
    
    // Test Case 1
    vector<string> ips = {};
    cout << "Test Case 1: " << minimal_spanning_subnet(ips) << endl;
    //Output: no input


    // Test Case 2
    ips = {"192.168.1.1", "192.168.1.2", "192.168.1.3"};
    cout << "Test Case 2: " << minimal_spanning_subnet(ips) << endl;
    // Output: 192.168.1.0/30

    // Test Case 3
    ips = {"192.168.1.1", "192.168.2.1", "192.169.1.1"};
    cout << "Test Case 3: " << minimal_spanning_subnet(ips) << endl;
    // Output: 192.168.0.0/15

    // Test Case 4
    ips = {"192.168.1.1"};
    cout << "Test Case 4: " << minimal_spanning_subnet(ips) << endl;
    // Output: 192.168.1.1/32

    // Test Case 5
    ips = {"1.1.1.1", "1.1.0.0"};
    cout << "Test Case 5: " << minimal_spanning_subnet(ips) << endl;
    // Output: 1.1.0.0/23

    return 0;
}
