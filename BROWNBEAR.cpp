#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#ifdef _WIN32  // if the current operating system is Windows
#include <windows.h>  // WriteConsoleW
#endif

#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>
#include <iomanip>
#include <cstdio>
#include <io.h>
#include <fcntl.h>

#include <filesystem>
using namespace std;

using namespace std;
namespace fs = std::filesystem;

//fonctions 
void saveKeyToFile(const std::string& key, const std::string& fileName);
void saveKeys(const std::string& cipherKey, const std::string& cipherKeyA, const std::string& cipherKeyB,
	const std::string& aesKey, const std::string& iv);
std::string readKeyFromFile(const std::string& fileName);
void loadKeys(std::string& cipherKey, std::string& cipherKeyA, std::string& cipherKeyB,
	std::string& aesKey, std::string& iv);

void decryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& aesKey, const std::string& iv);
void encryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& aesKey, const std::string& iv);

string lowerCaseString(string& source);
string special_shuffle(std::string s);
string encryptAES(const std::string& plaintext, const std::string& key, const std::string& iv);
string decryptAES(const std::string& ciphertext, const std::string& key, const std::string& iv);
string generateAESKey();
string generateIV();
string base64Encode(const std::string& input);
string base64Decode(const std::string& input);
bool substitution(string& source, string cipherKey, string& destination);
bool Encrypted(string& destination, string cipherKeyA, string& encrypted);
bool Encrypted2(string& destination, string cipherKeyB, string& encrypted2);
bool desubstitution(string& source, string cipherKey, string& original);
bool Decrypted(string& sourceB, string cipherKeyA, string& decrypted);
bool Decrypted2(string& sourceB2, string cipherKeyb, string& sourceB);
const int MAX = 26;

//ʕ´• ᴥ•̥`ʔ UTF8
void wprint(std::wstring message)
{
#ifdef _WIN32
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD n_written;
	WriteConsoleW(handle, message.c_str(), (DWORD)message.size(), &n_written, NULL);
#else
	std::wcout << message;
#endif
}

//BROWNBEAR MAIN
int main()
{
	string source;
	string cipherKey;
	string cipherKeyA;
	string cipherKeyB;
	string destination;
	string original;
	string encrypted;
	string encrypted2;
	string sourceB;
	string sourceB2;
	string decrypted;
	string password;
	string aesKey;
	string alphabet = "/abcdefghijklmnopqrstuvwxyz0123456789-+.,*";
	std::string key, iv, text;
	loadKeys(cipherKey, cipherKeyA, cipherKeyB, aesKey, iv);
	ifstream inFile;
	system("color 6F");
	system("TITLE BROWNBEAR");

	int choice;
	bool gameOn = true;
	while (gameOn != false) {
		cout << "============================================================================================\n";
		cout << "                                     B R O W N B E A R\n";
		cout << "                                    -------------------";
		cout << " \n";
		wprint(L"                                         \u0295\u00b4\u2022\u0020\u1d25\u2022\u0325\u0060\u0294\n");
		cout << " \n";
		cout << "============================================================================================\n";
		cout << "   \n";
		cout << " [1] ENCRYPT TEXT\n";
		cout << " [2] DECRYPT TEXT\n";
		cout << " \n";
		cout << " [3] ENCRYPT FILES\n";
		cout << " [4] DECRYPT FILES\n";
		cout << " [5] ENCRYPT FOLDER\n";
		cout << " [6] DECRYPT FOLDER\n";
		cout << " \n";
		cout << " [7] SET KEYS\n";
		cout << " [8] GENERATE A NEW KEY\n";
		cout << " [9] SAVES KEYS\n";
		cout << " \n";
		cout << " [10] EXIT\n";
		cout << " \n";
		cout << "   \n";
		cout << "============================================================================================\n";
		cout << "                        Enter your choice and press enter: \n";
		cout << "============================================================================================\n";
		cout << "   \n";

		cin >> choice;

		string base64Encoded;
		string encryptedAES;
		string decryptedAES;

		switch (choice)
		{
		case 1:
			try {
				system("cls");
				cout << "Please enter a string: " << endl;
				cin >> source;
				lowerCaseString(source);
				substitution(source, cipherKey, destination);
				Encrypted(destination, cipherKeyA, encrypted);
				Encrypted2(encrypted, cipherKeyB, encrypted2);

				// Encrypt the encrypted2 string using AES
				encryptedAES = encryptAES(encrypted2, key, iv);

				// Base64 encode the encrypted data for safe transmission
				base64Encoded = base64Encode(encryptedAES);

				// Debug output
				cout << "Encrypted text: " << base64Encoded << endl;
			}
			catch (const std::exception& e) {
				cerr << "Error occurred during encryption: " << e.what() << endl;
			}

			break;

		case 2:
			try {
				system("cls");
				cout << "Please enter a string: " << endl;
				cin >> sourceB2;

				// Decode the base64-encoded ciphertext
				sourceB2 = base64Decode(sourceB2);

				// Decrypt the ciphertext using AES
				decryptedAES = decryptAES(sourceB2, key, iv);

				// Perform necessary transformations (if any) to get the original plaintext
				// For example, you might need to desubstitution here
				sourceB2 = decryptedAES;
				lowerCaseString(sourceB2);
				Decrypted2(sourceB2, cipherKeyB, sourceB);
				Decrypted(sourceB, cipherKeyA, decrypted);
				desubstitution(decrypted, cipherKey, original);

				// Debug output
				cout << "Original text: " << original << endl;
			}
			catch (const std::exception& e) {
				cerr << "Error occurred during decryption: " << e.what() << endl;
			}

			break;
		case 3: // Encrypt a file
			try {
				system("cls");
				std::string inputFile, outputFile;
				std::cout << "Enter the path to the input file: ";
				std::getline(std::cin >> std::ws, inputFile); // Read input file path

				// Check if the input file path starts and ends with a double quote
				if (!inputFile.empty() && inputFile.front() == '"' && inputFile.back() == '"') {
					// Remove the double quotes at the beginning and end
					inputFile = inputFile.substr(1, inputFile.size() - 2);
				}

				std::cout << "Enter the path to the output file: ";
				std::getline(std::cin >> std::ws, outputFile); // Read output file path

				// Check if the output file path starts and ends with a double quote
				if (!outputFile.empty() && outputFile.front() == '"' && outputFile.back() == '"') {
					// Remove the double quotes at the beginning and end
					outputFile = outputFile.substr(1, outputFile.size() - 2);
				}

				encryptFile(inputFile, outputFile, aesKey, iv);
			}
			catch (const std::exception& e) {
				std::cerr << "Error occurred while encrypting file: " << e.what() << std::endl;
			}
			break;
		case 4: // Decrypt a file
			try {
				system("cls");
				std::string inputFile, outputFile;
				std::cout << "Enter the path to the input file: ";
				std::getline(std::cin >> std::ws, inputFile); // Read input file path

				// Check if the input file path starts and ends with a double quote
				if (!inputFile.empty() && inputFile.front() == '"' && inputFile.back() == '"') {
					// Remove the double quotes at the beginning and end
					inputFile = inputFile.substr(1, inputFile.size() - 2);
				}

				std::cout << "Enter the path to the output file: ";
				std::getline(std::cin >> std::ws, outputFile); // Read output file path

				// Check if the output file path starts and ends with a double quote
				if (!outputFile.empty() && outputFile.front() == '"' && outputFile.back() == '"') {
					// Remove the double quotes at the beginning and end
					outputFile = outputFile.substr(1, outputFile.size() - 2);
				}

				decryptFile(inputFile, outputFile, aesKey, iv);
			}
			catch (const std::exception& e) {
				std::cerr << "Error occurred while decrypting file: " << e.what() << std::endl;
			}
			break;
		case 5: // Encrypt a folder
			try {
				system("cls");
				std::string folderPath, outputPath;
				std::cout << "Enter the path to the folder to encrypt: ";
				std::getline(std::cin >> std::ws, folderPath); // Read folder path

				// Check if the folder path starts and ends with double quotes
				if (!folderPath.empty() && folderPath.front() == '"' && folderPath.back() == '"') {
					// Remove the starting and ending double quotes
					folderPath = folderPath.substr(1, folderPath.size() - 2);
				}

				std::cout << "Enter the path to the output folder: ";
				std::getline(std::cin >> std::ws, outputPath); // Read output folder path

				// Check if the output folder path starts and ends with double quotes
				if (!outputPath.empty() && outputPath.front() == '"' && outputPath.back() == '"') {
					// Remove the starting and ending double quotes
					outputPath = outputPath.substr(1, outputPath.size() - 2);
				}

				// Iterate through files in the folder
				for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
					if (entry.is_regular_file()) {
						std::string inputFile = entry.path().string();
						std::string outputFile = outputPath + "\\" + entry.path().filename().string() + ".encrypted";
						encryptFile(inputFile, outputFile, aesKey, iv);
					}
				}
				std::cout << "Folder encryption completed successfully." << std::endl;
			}
			catch (const std::exception& e) {
				std::cerr << "Error occurred while encrypting folder: " << e.what() << std::endl;
			}
			break;
		case 6: // Decrypt a folder
			try {
				system("cls");
				std::string folderPath, outputPath;
				std::cout << "Enter the path to the folder to decrypt: ";
				std::getline(std::cin >> std::ws, folderPath); // Read folder path

				// Check if the folder path starts and ends with double quotes
				if (!folderPath.empty() && folderPath.front() == '"' && folderPath.back() == '"') {
					// Remove the starting and ending double quotes
					folderPath = folderPath.substr(1, folderPath.size() - 2);
				}

				std::cout << "Enter the path to the output folder: ";
				std::getline(std::cin >> std::ws, outputPath); // Read output folder path

				// Check if the output folder path starts and ends with double quotes
				if (!outputPath.empty() && outputPath.front() == '"' && outputPath.back() == '"') {
					// Remove the starting and ending double quotes
					outputPath = outputPath.substr(1, outputPath.size() - 2);
				}

				// Iterate through files in the folder
				for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
					if (entry.is_regular_file()) {
						std::string inputFile = entry.path().string();
						// Remove the ".encrypted" extension to get the original filename
						std::string originalFileName = entry.path().filename().stem().string();
						std::string outputFile = outputPath + "\\" + originalFileName;
						decryptFile(inputFile, outputFile, aesKey, iv);
					}
				}
				std::cout << "Folder decryption completed successfully." << std::endl;
			}
			catch (const std::exception& e) {
				std::cerr << "Error occurred while decrypting folder: " << e.what() << std::endl;
			}
			break;
		case 7:
			try {
				system("cls");
				cout << "Please enter the key1: " << endl;
				cin >> cipherKey;
				cout << "Please enter the key2: " << endl;
				cin >> cipherKeyA;
				cout << "Please enter the key3: " << endl;
				cin >> cipherKeyB;
				cout << "Enter AES key (16, 24, or 32 bytes): ";
				cin >> key;
				cout << "Enter Initialization Vector (IV) (16 bytes): ";
				cin >> iv;
			}
			catch (const std::exception& e) {
				cerr << "Error occurred during key management: " << e.what() << endl;
			}
			break;
		case 8:
			try {
				system("cls");
				std::cout << special_shuffle(alphabet) << "\n";
				std::cout << special_shuffle(alphabet) << "\n";
				std::cout << special_shuffle(alphabet) << "\n";
				key = generateAESKey();
				iv = generateIV();
				std::cout << "Generated AES key: " << key << std::endl;
				std::cout << "Generated IV: " << iv << std::endl;
			}
			catch (const std::exception& e) {
				cerr << "Error occurred during key generation: " << e.what() << endl;
			}
			break;
		case 9:
			try {
				system("cls");
				saveKeyToFile(cipherKey, "cipherKey.txt");
				saveKeyToFile(cipherKeyA, "cipherKeyA.txt");
				saveKeyToFile(cipherKeyB, "cipherKeyB.txt");
				saveKeyToFile(key, "aesKey.txt");
				saveKeyToFile(iv, "iv.txt");
			}
			catch (const std::exception& e) {
				cerr << "Error occurred while saving keys: " << e.what() << endl;
			}
			break;
		case 10:
			system("cls");
			cout << "End of Program.\n";
			gameOn = false;
			break;
		default:
			system("cls");
			cout << "I'm not sure to understand... \n";
			cout << "Are you sure you know how to write? maybe you should go back to school ;-)\n";
			cout << "What do you want to do?.\n";
			cout << "   \n";
			cin >> choice;
			break;
		}

	}
	return 0;
}

//converts all letters that are upper case to lower case in source
string lowerCaseString(string& source)
{
	if (source.empty()) {
		throw std::invalid_argument("Input string is empty");
	}

	for (unsigned i = 0; i < source.size(); ++i)
	{
		if (isupper(source.at(i)))
		{
			source.at(i) = tolower(source.at(i));
		}
	}
	return source;
}

//ENCRYPTION SUBSTITUTION
bool substitution(string& source, string cipherKey, string& destination)
{
	string alphabet = "/abcdefghijklmnopqrstuvwxyz0123456789-+.,*";

	destination = source; // To make sure the size of destination is the same as source

	if (source.empty()) {
		throw std::invalid_argument("Input string is empty");
	}

	if (cipherKey.empty()) {
		throw std::invalid_argument("Cipher key is empty");
	}

	for (unsigned int i = 0; i < source.size(); ++i) {
		char character = source.at(i);
		size_t found = alphabet.find(character);
		if (found == string::npos) {
			throw std::invalid_argument("Character '" + string(1, character) + "' in input string is not supported for substitution");
		}
		destination.at(i) = cipherKey.at(found);
	}

	return true;
}

bool Encrypted(string& destination, string cipherKeyA, string& encrypted)
{
	string alphabet = "/abcdefghijklmnopqrstuvwxyz0123456789-+.,*";

	encrypted = destination; // To make sure the size of destination is the same as source

	if (destination.empty()) {
		throw std::invalid_argument("Destination string is empty");
	}

	if (cipherKeyA.empty()) {
		throw std::invalid_argument("Cipher key is empty");
	}

	for (unsigned int i = 0; i < destination.size(); ++i) {
		char character = destination.at(i);
		size_t found = alphabet.find(character);
		if (found == string::npos) {
			throw std::invalid_argument("Character '" + string(1, character) + "' in destination string is not supported for encryption");
		}
		encrypted.at(i) = cipherKeyA.at(found);
	}

	return true;
}

bool Encrypted2(string& destination, string cipherKeyB, string& encrypted2)
{
	string alphabet = "/abcdefghijklmnopqrstuvwxyz0123456789-+.,*";

	encrypted2 = destination; // To make sure the size of destination is the same as source

	if (destination.empty()) {
		throw std::invalid_argument("Destination string is empty");
	}

	if (cipherKeyB.empty()) {
		throw std::invalid_argument("Cipher key is empty");
	}

	for (unsigned int i = 0; i < destination.size(); ++i) {
		char character = destination.at(i);
		size_t found = alphabet.find(character);
		if (found == string::npos) {
			throw std::invalid_argument("Character '" + string(1, character) + "' in destination string is not supported for encryption");
		}
		encrypted2.at(i) = cipherKeyB.at(found);
	}

	return true;
}

//AES ENCRYPTION
std::string encryptAES(const std::string& plaintext, const std::string& key, const std::string& iv) {
	EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
	if (!ctx) {
		throw std::runtime_error("Error creating EVP_CIPHER_CTX");
	}

	if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (const unsigned char*)key.c_str(), (const unsigned char*)iv.c_str()) != 1) {
		EVP_CIPHER_CTX_free(ctx);
		throw std::runtime_error("Error initializing AES encryption");
	}

	int len;
	int ciphertext_len;
	std::string ciphertext(plaintext.size() + AES_BLOCK_SIZE, '\0');
	if (EVP_EncryptUpdate(ctx, (unsigned char*)&ciphertext[0], &len, (const unsigned char*)plaintext.c_str(), plaintext.size()) != 1) {
		EVP_CIPHER_CTX_free(ctx);
		throw std::runtime_error("Error updating AES encryption");
	}
	ciphertext_len = len;

	if (EVP_EncryptFinal_ex(ctx, (unsigned char*)&ciphertext[ciphertext_len], &len) != 1) {
		EVP_CIPHER_CTX_free(ctx);
		throw std::runtime_error("Error finalizing AES encryption");
	}
	ciphertext_len += len;

	EVP_CIPHER_CTX_free(ctx);

	// Resize the ciphertext to the actual size
	ciphertext.resize(ciphertext_len);

	return ciphertext;
}

// Padding function for AES encryption
std::string addPadding(const std::string& input) {
	int paddingSize = AES_BLOCK_SIZE - (input.length() % AES_BLOCK_SIZE);
	char paddingChar = paddingSize;
	return input + std::string(paddingSize, paddingChar);
}




//DECRYPTION SUBSTITUTION
bool desubstitution(string& decrypted, string cipherKey, string& original)
{
	string alphabet = "/abcdefghijklmnopqrstuvwxyz0123456789-+.,*";

	original = decrypted; // To make sure the size of original is the same as source

	if (decrypted.empty()) {
		throw std::invalid_argument("Decrypted string is empty");
	}

	if (cipherKey.empty()) {
		throw std::invalid_argument("Cipher key is empty");
	}

	for (unsigned int i = 0; i < decrypted.size(); ++i) {
		char character = decrypted.at(i);
		size_t found = cipherKey.find(character);
		if (found == string::npos) {
			throw std::invalid_argument("Character '" + string(1, character) + "' in decrypted string is not supported for decryption");
		}
		original.at(i) = alphabet.at(found);
	}

	return true;
}

bool Decrypted(string& sourceB, string cipherKeyA, string& decrypted)
{
	string alphabet = "/abcdefghijklmnopqrstuvwxyz0123456789-+.,*";

	decrypted = sourceB; // To make sure the size of decrypted is the same as sourceB

	if (sourceB.empty()) {
		throw std::invalid_argument("SourceB string is empty");
	}

	if (cipherKeyA.empty()) {
		throw std::invalid_argument("Cipher key is empty");
	}

	for (unsigned int i = 0; i < sourceB.size(); ++i) {
		char character = sourceB.at(i);
		size_t found = cipherKeyA.find(character);
		if (found == string::npos) {
			throw std::invalid_argument("Character '" + string(1, character) + "' in sourceB string is not supported for decryption");
		}
		decrypted.at(i) = alphabet.at(found);
	}

	return true;
}

bool Decrypted2(string& sourceB2, string cipherKeyB, string& sourceB)
{
	string alphabet = "/abcdefghijklmnopqrstuvwxyz0123456789-+.,*";

	sourceB = sourceB2; // To make sure the size of sourceB is the same as sourceB2

	if (sourceB2.empty()) {
		throw std::invalid_argument("SourceB2 string is empty");
	}

	if (cipherKeyB.empty()) {
		throw std::invalid_argument("Cipher key is empty");
	}

	for (unsigned int i = 0; i < sourceB2.size(); ++i) {
		char character = sourceB2.at(i);
		size_t found = cipherKeyB.find(character);
		if (found == string::npos) {
			throw std::invalid_argument("Character '" + string(1, character) + "' in sourceB2 string is not supported for decryption");
		}
		sourceB.at(i) = alphabet.at(found);
	}

	return true;
}

// AES decryption function
std::string decryptAES(const std::string& ciphertext, const std::string& key, const std::string& iv) {
	EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
	if (!ctx) {
		throw std::runtime_error("Error creating EVP_CIPHER_CTX");
	}

	if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (const unsigned char*)key.c_str(), (const unsigned char*)iv.c_str()) != 1) {
		EVP_CIPHER_CTX_free(ctx);
		throw std::runtime_error("Error initializing AES decryption");
	}

	int len;
	int plaintext_len;
	std::string plaintext(ciphertext.size() + AES_BLOCK_SIZE, '\0');

	if (EVP_DecryptUpdate(ctx, (unsigned char*)&plaintext[0], &len, (const unsigned char*)ciphertext.c_str(), ciphertext.size()) != 1) {
		EVP_CIPHER_CTX_free(ctx);
		throw std::runtime_error("Error updating AES decryption");
	}
	plaintext_len = len;

	if (EVP_DecryptFinal_ex(ctx, (unsigned char*)&plaintext[plaintext_len], &len) != 1) {
		EVP_CIPHER_CTX_free(ctx);
		throw std::runtime_error("Error finalizing AES decryption");
	}
	plaintext_len += len;

	EVP_CIPHER_CTX_free(ctx);

	// Remove padding
	plaintext.resize(plaintext_len);

	return plaintext;
}



//AES FILES
// Function to encrypt a file using AES key and IV
void encryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& aesKey, const std::string& iv) {
	// Open the input file for reading
	std::ifstream inFile(inputFile, std::ios::binary);
	if (!inFile) {
		throw std::runtime_error("Unable to open input file for reading");
	}

	// Open the output file for writing
	std::ofstream outFile(outputFile, std::ios::binary);
	if (!outFile) {
		throw std::runtime_error("Unable to open output file for writing");
	}

	// Read the content of the input file into memory
	std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());

	// Encrypt the content using AES encryption
	std::string encryptedContent = encryptAES(content, aesKey, iv);

	// Write the encrypted content to the output file
	outFile << encryptedContent;

	// Close the files
	inFile.close();
	outFile.close();

	std::cout << "File encrypted successfully.\n";
}

// Function to decrypt a file using AES key and IV
void decryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& aesKey, const std::string& iv) {
	// Open the input file for reading
	std::ifstream inFile(inputFile, std::ios::binary);
	if (!inFile) {
		throw std::runtime_error("Unable to open input file for reading");
	}

	// Open the output file for writing
	std::ofstream outFile(outputFile, std::ios::binary);
	if (!outFile) {
		throw std::runtime_error("Unable to open output file for writing");
	}

	// Read the content of the input file into memory
	std::string encryptedContent((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());

	// Decrypt the content using AES decryption
	std::string decryptedContent = decryptAES(encryptedContent, aesKey, iv);

	// Write the decrypted content to the output file
	outFile << decryptedContent;

	// Close the files
	inFile.close();
	outFile.close();

	std::cout << "File decrypted successfully.\n";
}



//BASE64
std::string base64Encode(const std::string& input) {
	BIO* bio, * b64;
	BUF_MEM* bufferPtr;

	b64 = BIO_new(BIO_f_base64());
	if (!b64) {
		throw std::runtime_error("Error creating base64 BIO");
	}

	bio = BIO_new(BIO_s_mem());
	if (!bio) {
		BIO_free_all(b64);
		throw std::runtime_error("Error creating memory BIO");
	}

	bio = BIO_push(b64, bio);
	if (!bio) {
		BIO_free_all(b64);
		throw std::runtime_error("Error pushing base64 BIO");
	}

	BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
	if (BIO_write(bio, input.c_str(), input.length()) <= 0) {
		BIO_free_all(bio);
		throw std::runtime_error("Error writing to base64 BIO");
	}

	if (BIO_flush(bio) != 1) {
		BIO_free_all(bio);
		throw std::runtime_error("Error flushing base64 BIO");
	}

	BIO_get_mem_ptr(bio, &bufferPtr);
	if (!bufferPtr) {
		BIO_free_all(bio);
		throw std::runtime_error("Error getting memory pointer from base64 BIO");
	}

	std::string output(bufferPtr->data, bufferPtr->length);

	BIO_free_all(bio);

	return output;
}

std::string base64Decode(const std::string& input) {
	// Create a BIO object for Base64 decoding
	BIO* b64 = BIO_new(BIO_f_base64());
	if (!b64) {
		throw std::runtime_error("Error creating BIO for Base64 decoding");
	}

	// Ignore newline characters during decoding
	BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);

	// Create a memory BIO for reading from input
	BIO* bio = BIO_new_mem_buf(input.data(), input.size());
	if (!bio) {
		BIO_free_all(b64);
		throw std::runtime_error("Error creating memory BIO for Base64 decoding");
	}

	// Push the Base64 BIO onto the memory BIO stack
	BIO_push(b64, bio);

	// Allocate memory for decoded data
	std::unique_ptr<char[]> decodedBuffer(new char[input.size() * 3 / 4 + 1]); // Maximum possible length

	// Read and decode the input data
	int decodedLength = BIO_read(b64, decodedBuffer.get(), input.size() * 3 / 4);
	if (decodedLength < 0) {
		BIO_free_all(b64);
		throw std::runtime_error("Error decoding Base64 data");
	}

	// Ensure null termination
	decodedBuffer[decodedLength] = '\0';

	// Clean up resources
	BIO_free_all(b64);

	// Convert decoded data to string
	return std::string(decodedBuffer.get());
}




//RANDOM GENERATION
std::string special_shuffle(std::string s) {
	if (s.size() < 3) return s;

	auto begin = std::find_if(s.begin(), s.end(), ::isprint);
	auto end = std::find_if(s.rbegin(), s.rend(), ::isprint).base();

	if (std::distance(begin, end) < 3) return s; // Check if there are at least 3 printable characters

	std::vector<char> chars(begin, end);
	srand(static_cast<unsigned int>(time(nullptr))); // Seed the random number generator

	for (size_t i = 1; i < chars.size() - 1; ++i) {
		size_t j = rand() % (chars.size() - 2) + 1;
		std::swap(chars[i], chars[j]);
	}

	std::copy(chars.begin(), chars.end(), begin);

	return s;
}

//AES
std::string generateAESKey() {
	unsigned char key[AES_BLOCK_SIZE] = { 0 };
	if (RAND_bytes(key, AES_BLOCK_SIZE) != 1) {
		throw std::runtime_error("Error generating random AES key");
	}

	std::ostringstream oss;
	for (int i = 0; i < AES_BLOCK_SIZE; ++i) {
		oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(key[i]);
	}
	return oss.str();
}

// IV
std::string generateIV() {
	unsigned char iv[AES_BLOCK_SIZE] = { 0 };
	RAND_bytes(iv, AES_BLOCK_SIZE);
	char hex_iv[AES_BLOCK_SIZE * 2 + 1] = { 0 };
	for (int i = 0; i < AES_BLOCK_SIZE; ++i)
		sprintf_s(hex_iv + 2 * i, sizeof(hex_iv) - 2 * i, "%02X", iv[i]);
	return std::string(hex_iv);
}




//KEY MANAGEMENT
void saveKeyToFile(const std::string& key, const std::string& fileName) {
	std::ofstream outFile(fileName);
	if (outFile.is_open()) {
		outFile << key;
		outFile.close();
		std::cout << "Key saved to file: " << fileName << std::endl;
	}
	else {
		throw std::runtime_error("Unable to open file for writing");
	}
}

void saveKeys(const std::string& cipherKey, const std::string& cipherKeyA, const std::string& cipherKeyB,
	const std::string& aesKey, const std::string& iv) {
	saveKeyToFile(cipherKey, "cipherKey.txt");
	saveKeyToFile(cipherKeyA, "cipherKeyA.txt");
	saveKeyToFile(cipherKeyB, "cipherKeyB.txt");
	saveKeyToFile(aesKey, "aesKey.txt");
	saveKeyToFile(iv, "iv.txt");
}

std::string readKeyFromFile(const std::string& fileName) {
	std::ifstream inFile(fileName);
	if (inFile.is_open()) {
		std::string key;
		inFile >> key;
		inFile.close();
		return key;
	}
	else {
		throw std::runtime_error("Unable to open file for reading");
	}
}

void loadKeys(std::string& cipherKey, std::string& cipherKeyA, std::string& cipherKeyB,
	std::string& aesKey, std::string& iv) {
	cipherKey = readKeyFromFile("cipherKey.txt");
	cipherKeyA = readKeyFromFile("cipherKeyA.txt");
	cipherKeyB = readKeyFromFile("cipherKeyB.txt");
	aesKey = readKeyFromFile("aesKey.txt");
	iv = readKeyFromFile("iv.txt");
}