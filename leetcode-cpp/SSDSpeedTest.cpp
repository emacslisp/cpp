#include <iostream>
#include <fstream>
#include <chrono>

int main() {
    const std::string testFileName = "nvme_speed_test.tmp";
    const std::string testText = "This is a test to measure NVMe SSD speed.";

    // Measure write speed
    auto startWrite = std::chrono::steady_clock::now();
    std::ofstream outputFile(testFileName, std::ios::binary);
    for (int i = 0; i < 1000000; ++i) { // Write 1000 times to create a larger file
        outputFile << testText;
    }
    outputFile.close();
    auto endWrite = std::chrono::steady_clock::now();
    auto writeTime = std::chrono::duration_cast<std::chrono::milliseconds>(endWrite - startWrite).count();
    double writeSpeedMBps = (static_cast<double>(testText.length() * 1000) / writeTime);

    std::cout << "Write Speed: " << writeSpeedMBps << " MB/s" << std::endl;

    // Measure read speed
    auto startRead = std::chrono::steady_clock::now();
    std::ifstream inputFile(testFileName, std::ios::binary);
    std::string fileContent((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();
    auto endRead = std::chrono::steady_clock::now();
    auto readTime = std::chrono::duration_cast<std::chrono::milliseconds>(endRead - startRead).count();
    double readSpeedMBps = (static_cast<double>(fileContent.length()) / readTime);

    std::cout << "Read Speed: " << readSpeedMBps << " MB/s" << std::endl;

    // Clean up the test file
    remove(testFileName.c_str());

    return 0;
}
