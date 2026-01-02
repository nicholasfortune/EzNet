#include <fstream>
#include <filesystem>
#include <iostream>
#include <vector>
#include "../tests/network.h"
#include "../include/eznet.h"

//char "network_test_file.binary"[] = "network_test_file.binary";

bool create_network() {
    std::vector<uint32_t> layers = {2, 3, 2};
    NeuralNetwork::network new_network = NeuralNetwork::create_network(layers);

    /* Expected data:
    config data[0] = {2} (config version 1 says there is only one config uint32_t, and it is responsible for input size)
    layers should have 2 NeuralNetwork::layer instances (layers[0] is simply for input size, not actually a layer), each with filled out input and output sizes, and proper amounts of weights and biases.

    layer 0:
    weights: 6
    biases: 3
    input size: 2
    output size: 3

    layer 1:
    weights: 6
    biases: 2
    input size: 3
    output size: 2
    */

    if (new_network.config_data.size() != 1) {std::cerr << "\033[31m[ ERROR ]\033[0m network: create_network: config metadata size isn't as expected.\n";return false;}
    if (new_network.config_data[0] != 2) {std::cerr << "\033[31m[ ERROR ]\033[0m network: create_network: config metadata isn't as expected.\n";return false;}
    if (new_network.layers.size() != 2) {std::cerr << "\033[31m[ ERROR ]\033[0m network: create_network: amount of layers isn't as expected.\n";return false;}

    if (new_network.layers[0].weights.size() != 6) {std::cerr << "\033[31m[ ERROR ]\033[0m network: create_network: amount of weights isn't as expected.\n";return false;}
    if (new_network.layers[0].biases.size() != 3) {std::cerr << "\033[31m[ ERROR ]\033[0m network: create_network: amount of biases isn't as expected.\n";return false;}
    if (new_network.layers[0].input_size != 2) {std::cerr << "\033[31m[ ERROR ]\033[0m network: create_network: input size isn't as expected.\n";return false;}
    if (new_network.layers[0].output_size != 3) {std::cerr << "\033[31m[ ERROR ]\033[0m network: create_network: output size isn't as expected.\n";return false;}

    if (new_network.layers[1].weights.size() != 6) {std::cerr << "\033[31m[ ERROR ]\033[0m network: create_network: amount of weights isn't as expected.\n";return false;}
    if (new_network.layers[1].biases.size() != 2) {std::cerr << "\033[31m[ ERROR ]\033[0m network: create_network: amount of biases isn't as expected.\n";return false;}
    if (new_network.layers[1].input_size != 3) {std::cerr << "\033[31m[ ERROR ]\033[0m network: create_network: input size isn't as expected.\n";return false;}
    if (new_network.layers[1].output_size != 2) {std::cerr << "\033[31m[ ERROR ]\033[0m network: create_network: output size isn't as expected.\n";return false;}

    return true;
}

bool save_network() {
    std::vector<uint32_t> layers = {2, 3, 2};
    NeuralNetwork::network new_network = NeuralNetwork::create_network(layers);

    std::fstream file("network_test_file.binary", std::ios::in | std::ios::out | std::ios::binary);
    if (!file.is_open()) {std::cerr << "\033[31m[ ERROR ]\033[0m network: save_network: failed to open \"" << "network_test_file.binary" << "\".\n";return false;}

     

    file.close();
    return true;
}

bool network() {
    bool success = true;
    // insert_bytes
    if (!create_network()) {
        std::cout << "\033[31m[ FAILED ]\033[0m network: create_network()\n";
        std::cout << "\033[31m[ FATAL ]\033[0m network: create_network() was required for further tests, quitting network test.\n";
        success = false;
    } else {
        std::cout << "\033[32m[ PASSED ]\033[0m network: create_network()\n";
    }
    if (!success) {std::cout << "\033[33m[ NOTICE ]\033[0m network: \033[1msome tests failed, check the binary test file \"" << 404 << "\" at the working directory.\033[0m" << std::endl;}
    else {}

    return success;
}